#pragma once

#include <iostream>
#include "armadillo"
#include <string>

using namespace std;
using namespace arma;

class planets {
public:
    //contructor
    planets();
    //overload constructor
    planets(string, int, double);
    //Accessor function
    string getName() const;
    // getName - return the name

private:
    string newName;
    int newHeight;
    double newWeight;
}
