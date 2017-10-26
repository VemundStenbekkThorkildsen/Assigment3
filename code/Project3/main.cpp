#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "solarSystem.h"
#include "body.h"
#include "components.h"
#include "verlet.h"

using namespace std;

int main()
{
    cout << "Type in which solar model you want to use. Type 'two' for Sun and Earth model, type 'three' for the three planet model, type 'perihelion' for the "
            "mercury and sun model and 'final' for the final solarsystem: " << endl;
    string answer = ""; //Converting user input into string
    getline(cin, answer);
    cout << "Now choose what integrator you want to use, either Euler forward method (type 'Euler') or velocity Verlet method"
            "(type 'Verlet'): " << endl;
    string answer2 = "";
    getline(cin, answer2);

    solarSystem solarSystem;
    double massSun = 2e30;
    //First model
    if(answer=="two"){
        solarSystem.planet(components(0,0,0), components(0,0,0), 1.0);
        solarSystem.planet(components(0,0,0), components(0,2*3.14, 0), 3e-6);
    }

    //Second model
    if(answer=="three"){
        //Sun
        solarSystem.planet(components(0.0070897,-0.0014884,0),components(3.778e-6,-5.67e-6,0)*365,1); //Velocity so momentum is zero
        //Earth
        solarSystem.planet(components(0.91708972,0.41851161,0),components(-7.708603521431721E-03, 1.546968939253316E-02, 0)*365,3.00349e-6);
        //Jupiter
        solarSystem.planet(components(-7.4329103,1.55851161,0),components(3.983653264921868E-03, -5.994727676715690E-03, 0)*365,0.000954198);
    }
    //Third model
    //Perihelion
    if(answer=="perihelion"){
        solarSystem.planet(components(0.0,0.0,0.0), components(0.0,0.0,0.0), 1.0);
        solarSystem.planet(components(0.3075,0.0,0.0), components(0.0,12.44,0.0), (3.3e23/massSun));
    }
    //Velocities multiplied by 365 to get the unit in AU per year
    //Final model
    if(answer=="final"){
        //Sun
        solarSystem.planet( components(2.213296131976958E-03, 5.740795718142255E-03, -1.300333836064062E-04), components(-5.236918819978495E-06, 5.487345385589584E-06, 1.229796132639033E-07)*365, 1.0);
        //Mercury
        solarSystem.planet( components(-3.004912369967300E-01, -3.291939141643662E-01, 2.715228654907219E-04), components(1.515329129252778E-02, -1.756496278615964E-02, -2.826250874177743E-03)*365, (3.3e23/massSun));
        //Venus
        solarSystem.planet( components(-6.581496097890938E-01, 2.867555966500064E-01, 4.183181369002011E-02), components(-8.016961988509333E-03, -1.870054841427580E-02, 2.058573306112892E-04)*365, (4.9e24/massSun));
        //Earth
        solarSystem.planet( components(9.008745231347060E-01, 4.354368878037240E-01, -1.541802405455852E-04), components(-7.708603521431721E-03, 1.546968939253316E-02, -8.760625935033381E-07)*365, (6e24/massSun));
        //Mars
        solarSystem.planet( components(-1.571535279041875E+00, 5.485373678700209E-01, 4.986713818681023E-02), components(-4.043755947260121E-03, -1.202794362189266E-02, -1.529311915880650E-04)*365, (6.6e23/massSun));
        //Jupiter
        solarSystem.planet( components(-4.576765120608809E+00, -2.933101794720733E+00, 1.145345160230888E-01), components(3.983653264921868E-03, -5.994727676715690E-03, -6.419350084082065E-05)*365, (1.9e27/massSun));
        //Saturn
        solarSystem.planet( components(-3.421974997678738E-01, -1.004964711398301E+01, 1.883533993066547E-01), components(5.269582020005830E-03, -2.084428240279003E-04,-2.058055841284417E-04)*365, (5.5e26/massSun));
        //Uranus
        solarSystem.planet( components(1.785610483247027E+01, 8.816513066524889E+00, -1.985838436058382E-01), components(-1.770055721315316E-03, 3.343297659935217E-03, 3.541938833576243E-05)*365, (8.8e25/massSun));
        //Neptun
        solarSystem.planet( components(2.861564756730530E+01, -8.815304499659160E+00, -4.779424150910477E-01), components(9.028408345768814E-04, 3.018504750805792E-03, -8.276897020654766E-05)*365, (1.03e26/massSun));
        //Pluto
        solarSystem.planet( components(1.055312162621389E+01, -3.171190456877188E+01, 3.407868079992951E-01), components(3.049404197428726E-03, 3.449806073416288E-04, -9.077532832745567E-04)*365, (1.31e22/massSun));
    }
    vector<body> &planets = solarSystem.planets(); //List of all planets (objects)
    double n = 10000; //Number of steps
    double years = 50; //Years we want the planets to rotate around the sun
    double h = years/(n); //Number of integration points
    verlet solver(h); //Integration object
    string position = "position.txt"; //Name of the output file
    ofstream outfile(position);
    string perihelion = "perihelion.txt";
    ofstream outfile2(perihelion);
    string perihelionDistance = "perihelionDistance.txt";
    ofstream outfile3(perihelionDistance);
    string totalEnergy = "totalEnergy.txt";
    ofstream outfile4(totalEnergy);
    //For-loop changing what planet we are dealing with
    for (int i = 0; i<planets.size(); i++){
        body &planet = planets[i];
        cout << "Position of planets: " << planet.position << " and velocity of planets " << planet.velocity << endl;
    }
    outfile << endl;
    outfile2 << endl;
    outfile3 << endl;
    outfile4 << endl;
    //Integration-loop with n steps at an object "solver"
    for (int i = 0; i<n; i++){
        solver.integrator(solarSystem, answer2);
        solarSystem.toFile(outfile, outfile2, outfile3, outfile4);
    }

    cout << "The solarsystem has: " << solarSystem.planets().size() << " objects" << endl;

    return 0;
}
