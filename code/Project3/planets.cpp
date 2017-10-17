#include "planets.h"

planets::planets(){
    newHeight = 0;
    newWeight = 0.0;
}

planets::planets(string name, double , double weight){

    newName = name;
    newHeight = height;
    newWeight = weight;

}

string planets::getName() const{
    return newName;
}
