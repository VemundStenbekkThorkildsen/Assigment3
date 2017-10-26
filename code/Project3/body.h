#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

#include "components.h"

class body{

public:
    //Initializing contructor
    body();
    //Overload constructors
    body(components,components, double); //x,y,z-positions, x,y,z-velocities and mass of planet
    body(double x, double y, double z, double vx, double vy, double vz, double mass); //x,y,z-position, vx,vy,vz-velocity and mass of planet
    void zeroForce(); //To zero out previous force after one integration step

    //Global variables
    components position;
    components velocity;
    components force;
    double mass;
};
