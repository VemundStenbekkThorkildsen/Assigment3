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
    void beregne(); //Calculates forces between planets, potential and kinetic energy and angular momentum
    void zeroPlanitaryForces(); //Setting forces to zero for each integration step so not to stack


    //Getters to return "m_" values to other classes and main
    double getEp() const;
    int getTotalPlanets() const;
    double getEk() const;
    double getTotalE() const;
    double getTheta() const;
    double getPDistance() const;

    //Writing positions, perihelion angles, distance to perihelion angle and the total energy to ".txt" files
    void toFile(ofstream &file, ofstream &file2, ofstream &file3, ofstream &file4);
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
    double m_theta;
    double m_pDistance;
    double eps;//Error
    ofstream m_file;
};
