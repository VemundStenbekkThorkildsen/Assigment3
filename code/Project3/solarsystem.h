#pragma once
#include "body.h"
#include "components.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class solarSystem{

public:

    //Initializing constructors
    solarSystem();

    //Overload constructors
    void planet(components, components, double); //x,y,z-positions, x,y,z-velocities and mass of planet
    void zeroPlanitaryForces(); //Setting forces to zero for each integration step so not to stack
    void calcForce(); //Calculates forces between planets, potential and kinetic energy and angular momentum
    void calcEnergy(); //Calculating potential and kinetic energy and angular momentum
    void calcPerihelionAngular(ofstream &file2);


    //Getters to return members to other classes and main
    double getEp() const;
    int getTotalPlanets() const;
    double getEk() const;
    double getTotalE() const;
    double getTheta() const;
    double getPDistance() const;
    double getAngular() const;

    //Writing positions, perihelion angles and distance, total energy and angular momentum to ".txt" files
    void toFile(ofstream &file, ofstream &file2, ofstream &file3, ofstream &file4, ofstream &file5);
    //Global vector holding all the planets
    vector<body> &planets();

private:
    //Local variables
    double PcrossV;//Position crossed with velocity
    double AcrossV;//Distance between planets crossed with velocity
    double c;//Speed of light
    double G;//Newtons gravitational constant
    vector<body> m_planets;//Member vector for all planets
    double m_Ep;//Potential energy
    double m_Ek;//Kinetic energy
    double m_totalE;
    double pForces;//Relativistic force between planets
    double distance;//Distance between planets (number)
    double m_angularMomentum;
    double m_theta, r, r1, r2, x, x1, x2, y, y1, y2;
    double m_pDistance;
    double eps;//Error
    ofstream m_file;
};
