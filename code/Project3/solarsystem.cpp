#define _USE_MATH_DEFINES
#include <cmath>
#include "solarsystem.h"
#include "components.h"
#include <iomanip>


solarSystem::solarSystem():
    m_Ep(0),
    m_Ek(0)
{

}

void solarSystem::planet(components position, components velocity, double mass){
    m_planets.push_back(body(position, velocity, mass));
}
void solarSystem::zeroPlanitaryForces(){
    for(body &planet : m_planets) {
        planet.force.zeros(); //Setting the force to zero
    }
}
void solarSystem::calcForce(){

    zeroPlanitaryForces();
    G = 4*M_PI*M_PI;
    c = 63198;
    for (int i = 0; i<m_planets.size(); i++){
        body &planet1 = m_planets[i];

        for (int j = i+1; j<m_planets.size(); j++){
            body &planet2 = m_planets[j];
            components apart = planet1.position - planet2.position;
            distance = apart.length();

            //Relativistic force
            //components AcrossV = apart.cross(planet2.velocity);
            //components force = (((G*planet1.mass*planet2.mass)/(pow(distance, 3)))*apart)*(1 + 3*((AcrossV.lengthSquared())/(distance*distance*c*c)));

            //Newtonian force
            components force = ((G*planet1.mass*planet2.mass)/pow(distance,4))*apart;
            planet1.force -= force;
            planet2.force += force;
        }
    }
}
void solarSystem::calcEnergy(){

    G = 4*M_PI*M_PI; //Gravitational constant
    m_Ep = 0; //Resetting energy
    m_Ek = 0;
    for (int i = 0; i<m_planets.size(); i++){
        body &planet1 = m_planets[i];
        for (int j = i+1; j<m_planets.size(); j++){
            body &planet2 = m_planets[j];

            //Potential energy
            m_Ep = (-G*planet1.mass*planet2.mass)/distance;

        }
        //Kinetic and total energy
        m_Ek += 0.5*planet1.mass*planet1.velocity.lengthSquared();
        m_totalE = m_Ek + m_Ep;
    }
}
void solarSystem::calcPerihelionAngular(ofstream &file2){

    for (int i = 0; i<m_planets.size(); i++){
        body &planet1 = m_planets[i];

        for (int j = i+1; j<m_planets.size(); j++){
            body &planet2 = m_planets[j];

            //Perihelion
            m_pDistance = sqrt((planet2.position.index(1)*planet2.position.index(1))+(planet2.position.index(0)*planet2.position.index(0))); //Distance to perihelion
            r = ((planet2.position).lengthSquared()); //Updated current position of the planet to the sun
            x = (planet2.position.index(0)); //Current x-position
            y = (planet2.position.index(1)); //Current y-position
            if(((r1) < (r)) && ((r1) < (r2))){
                m_theta = (atan(y1 / x1)*((3600*180)/M_PI)); //Angle to perihelion
                //file2 << setprecision(15) << m_theta << endl;
            }
            x2=x1; //Setting previous previous step to previous step in x-direction
            x1=x; //Setting previous step to current step
            y2=y1; //Same, but for y-direction
            y1=y;
            r2=r1; //Same, but for the distance
            r1=r;

            //Angular momentum
            PcrossV = (planet2.position.cross(planet2.velocity)).length();
            m_angularMomentum = (planet2.mass*PcrossV);
        }
    }
}
double solarSystem::getEp() const{
    return m_Ep;
}
double solarSystem::getEk() const{
    return m_Ek;
}
double solarSystem::getTotalE() const{
    return m_totalE;
}
int solarSystem::getTotalPlanets() const{
    return m_planets.size();
}
double solarSystem::getTheta() const{
    return m_theta;
}
double solarSystem::getPDistance() const{
    return m_pDistance;
}
double solarSystem::getAngular() const{
    return m_angularMomentum;
}

void solarSystem::toFile(ofstream &file, ofstream &file2, ofstream &file3, ofstream &file4, ofstream &file5)
{

    for(body &planet : m_planets) {
        file << setprecision(10) << planet.position.x() << " " << setprecision(10) << planet.position.y() << " " << setprecision(10) << planet.position.z() << endl;
        //file4 << setprecision(10) << m_totalE << endl;
        //file5 << setprecision(10) << m_angularMomentum << endl;
    }
    file << endl;
    //file4 << endl;
    //file5 << endl;
    for(int i=0;i<1;i++){
        //file2 << setprecision(15) << m_theta << endl;
        //file3 << setprecision(15) << m_pDistance << endl;
    }
    //file2 << endl;
    //file3 << endl;
}

vector<body> &solarSystem::planets(){
    return m_planets;
}
