#include "body.h"

body::body(){

}

body::body(components pos, components vel, double mass_){
    position = pos;
    velocity = vel;
    mass = mass_;
}

body::body(double x, double y, double z, double vx, double vy, double vz, double mass_){
    position = components(x,y,z);
    velocity = components(vx,vy,vz);
    mass = mass_;
}
void body::zeroForce() {
    force.zeros();
}
