#include "components.h"
#include <cmath>
#include <iostream>
using namespace std;

components::components(){
    zeros();
}
components::components(double x, double y, double z){
    xyz[0] = x;
    xyz[1] = y;
    xyz[2] = z;
}

components components::cross(components otherVector)
{
    return components(y()*otherVector.z()-z()*otherVector.y(), z()*otherVector.x()-x()*otherVector.z(), x()*otherVector.y()-y()*otherVector.x());
}

double components::index(int num)
{
  return xyz[num];
}

double components::lengthSquared()
{
    // Returns the square of the length (or norm) of the vector
    return xyz[0]*xyz[0]+xyz[1]*xyz[1]+xyz[2]*xyz[2];
}

double components::length()
{
    // Returns the length (or norm) of the vector
    return sqrt(lengthSquared());
}

void components::zeros()
{
    xyz[0] = 0;
    xyz[1] = 0;
    xyz[2] = 0;
}

components &components::operator+=(double rhs)
{
    xyz[0] += rhs;
    xyz[1] += rhs;
    xyz[2] += rhs;
    return *this;
}

components &components::operator+=(components rhs)
{
    xyz[0] += rhs[0];
    xyz[1] += rhs[1];
    xyz[2] += rhs[2];
    return *this;
}

components &components::operator*=(double rhs)
{
    xyz[0] *= rhs;
    xyz[1] *= rhs;
    xyz[2] *= rhs;
    return *this;
}

components &components::operator*=(components rhs)
{
    xyz[0] *= rhs[0];
    xyz[1] *= rhs[1];
    xyz[2] *= rhs[2];
    return *this;
}

components &components::operator-=(double rhs)
{
    xyz[0] -= rhs;
    xyz[1] -= rhs;
    xyz[2] -= rhs;
    return *this;
}

components &components::operator-=(components rhs)
{
    xyz[0] -= rhs[0];
    xyz[1] -= rhs[1];
    xyz[2] -= rhs[2];
    return *this;
}

components &components::operator/=(double rhs)
{
    xyz[0] /= rhs;
    xyz[1] /= rhs;
    xyz[2] /= rhs;
    return *this;
}

components &components::operator/=(components rhs)
{
    xyz[0] /= rhs[0];
    xyz[1] /= rhs[1];
    xyz[2] /= rhs[2];
    return *this;
}

std::ostream &operator<<(std::ostream &os, const components &myVector) // Allows cout << myVector << endl;
{
    os << "[" << myVector.x() << ", " << myVector.y() << ", " << myVector.z() << "];";
    return os;
}
