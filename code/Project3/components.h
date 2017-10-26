#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class components{

public:
    //Initializing constructors
    components();
    //Overload contructor
    components(double, double, double); //position x,y,z
    double lengthSquared();
    double length();
    void zeros();
    components cross(components otherVector);
    double dot(components otherVector);
    double index(int num);
    void normalize();
    components normalized();

    // Getters and setters
    double x() const { return xyz[0]; }
    double y() const { return xyz[1]; }
    double z() const { return xyz[2]; }
    void setX(double x) { xyz[0] = x; }
    void setY(double y) { xyz[1] = y; }
    void setZ(double z) { xyz[2] = z; }

    // Convenience functions
    void print();
    void print(string name);
    friend ostream& operator<<(ostream& os, const components& myVector); // Allows cout << myVector << endl;

    // Operators
    double &operator()(int index) { return xyz[index]; } // Allows access like myVector(0)
    double &operator[](int index) { return xyz[index]; } // Allows access like myVector[0]
    components &operator+=(double rhs); // Componentwise addition with scalar
    components &operator+=(components rhs);   // Componentwise addition with vector
    components &operator*=(double rhs); // Componentwise multiplication with scalar
    components &operator*=(components rhs);   // Componentwise multiplicationwith vector
    components &operator-=(double rhs); // Componentwise subtraction with scalar
    components &operator-=(components rhs);   // Componentwise subtraction with vector
    components &operator/=(double rhs); // Componentwise division with scalar
    components &operator/=(components rhs);   // Componentwise division with vector


private:
    double xyz[3];
};
inline components operator+(components lhs, double rhs) {
    lhs += rhs;
    return lhs;
}

inline components operator+(double lhs, components rhs) {
    rhs += lhs;
    return rhs;
}

inline components operator+(components lhs, components rhs) {
    lhs += rhs;
    return lhs;
}

inline components operator-(components lhs, double rhs) {
    lhs -= rhs;
    return lhs;
}

inline components operator-(double lhs, components rhs) {
    rhs -= lhs;
    return rhs;
}

inline components operator-(components lhs, components rhs) {
    lhs -= rhs;
    return lhs;
}


inline components operator*(components lhs, double rhs) {
    lhs *= rhs;
    return lhs;
}

inline components operator*(double lhs, components rhs) {
    rhs *= lhs;
    return rhs;
}

inline components operator*(components lhs, components rhs) {
    lhs *= rhs;
    return lhs;
}


inline components operator/(components lhs, double rhs) {
    lhs /= rhs;
    return lhs;
}

inline components operator/(double lhs, components rhs) {
    rhs /= lhs;
    return rhs;
}

inline components operator/(components lhs, components rhs) {
    lhs /= rhs;
    return lhs;
}
