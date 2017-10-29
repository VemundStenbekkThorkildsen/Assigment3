#pragma once

#include "solarsystem.h"

class verlet{

public:
    //Initializing contructor
    verlet(double); //h, the number of integration points

    //Overload constructor
    void integrator(class solarSystem &system, string answer2, ofstream &file2); //Both Euler and Verlet integrators

private:
    //Local variables
    double m_h;
};
