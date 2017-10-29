#include "verlet.h"
#include "solarsystem.h"


verlet::verlet(double h):
    m_h(h)
{

}

void verlet::integrator(solarSystem &system, string answer2, ofstream &file2)
{

    //Euler forward method
    if(answer2=="Euler"){
        system.calcForce();
        system.calcEnergy();
        system.calcPerihelionAngular(file2);
        for(body &planet : system.planets()) {
            planet.velocity += (planet.force/planet.mass) * m_h;
            planet.position += planet.velocity*m_h;
        }
     }

    //Verlet velocity method
    if(answer2=="Verlet"){
        for (body &planet : system.planets()){
            components acc = planet.force/planet.mass;
            planet.velocity += 0.5*m_h*(acc);
            planet.position += (planet.velocity)*m_h;
        }
        system.planets()[0].position = components (0,0,0);
        system.calcForce();
        system.calcEnergy();
        system.calcPerihelionAngular(file2);
        for (body &planet : system.planets()){
            components acc = planet.force/planet.mass;
            planet.velocity += 0.5*m_h*(acc);
        }
    }
}
