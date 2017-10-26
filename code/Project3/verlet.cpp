#include "verlet.h"
#include "solarsystem.h"


verlet::verlet(double h):
    m_h(h)
{

}

void verlet::integrator(solarSystem &system, string answer2)
{

    //Euler forward method
    if(answer2=="Euler"){
        system.beregne();
        for(body &planet : system.planets()) {
            planet.velocity += (planet.force/planet.mass) * m_h;
            planet.position += planet.velocity*m_h;
        }
     }

    //Verlet velocity method
    if(answer2=="Verlet"){
        system.beregne();
        for (body &planet : system.planets()){
            components acc = planet.force/planet.mass;
            planet.position += (planet.velocity + 0.5*acc*m_h)*m_h;

            system.beregne();

            acc += planet.force/planet.mass;
            planet.velocity += 0.5*m_h*(acc);
        }
    }
}
