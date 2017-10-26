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
void solarSystem::beregne(){

    zeroPlanitaryForces();
    eps = 1e-6;
    G = 4*M_PI*M_PI;
    c = 63198;
    m_Ep = 0;
    m_Ek = 0;
    for (int i = 0; i<m_planets.size(); i++){
        body &planet1 = m_planets[i];

        for (int j = i+1; j<m_planets.size(); j++){
            body &planet2 = m_planets[j];
            components apart = planet1.position - planet2.position;
            distance = apart.length();

            //Perihelion
            components AcrossV = apart.cross(planet2.velocity);
            //components force = ((G*planet1.mass*planet2.mass)/pow(distance,3))*apart;
            components force = (((G*planet1.mass*planet2.mass)/(pow(distance, 3)))*apart)*(1 + 3*((AcrossV*AcrossV)/(distance*distance*c*c)));



            //Regular force, no relativity
            planet1.force -= force;
            planet2.force += force;
            m_Ep = (-G*planet1.mass*planet2.mass)/distance;
            PcrossV = planet2.position.cross(planet2.velocity).length();
            m_angularMomentum += (distance*distance*planet2.mass*PcrossV)/(distance*distance);


        }
        m_Ek += 0.5*planet1.mass*planet1.velocity.lengthSquared();
        m_totalE = m_Ek + m_Ep;
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

void solarSystem::toFile(ofstream &file, ofstream &file2, ofstream &file3, ofstream &file4)
{

    for(body &planet : m_planets) {
        file << setprecision(10) << planet.position.x() << " " << setprecision(10) << planet.position.y() << " " << setprecision(10) << planet.position.z() << endl;
    }
    file << endl;
    for(int i=0;i<1;i++){
        file2 << setprecision(10) << m_theta << endl;
        file3 << setprecision(10) << m_pDistance << endl;
        file4 << setprecision(10) << m_totalE << endl;
    }
    file2 << endl;
    file3 << endl;
    file4 << endl;
}
vector<body> &solarSystem::planets(){
    return m_planets;
}
