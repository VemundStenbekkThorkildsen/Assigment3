#include <iostream>
#include <armadillo>
#include <string>

#include "planets.h"

using namespace std;
using namespace arma;

int main()
{
    int n=50;
    double h=1./(n);
    vec angle(n);
    vec posx(n+1);
    vec posy(n+1);
    posx(0)=1;
    posy(0)=0;
    double r=1; //1 AU
    double d;
    double pi;
    pi=3.14;
    double GMsun = 4*pi*pi;


    vec speedx(n+1);
    vec speedy(n+1);
    posx(0) = 1;
    posy(0) = 0;
    speedx(0)=0;
    speedy(0)=1.8;

    vec vposx(n+1);
    vec vposy(n+1);
    vec vspeedx(n+1);
    vec vspeedy(n+1);
    vposx(0) = 1;
    vposy(0) = 0;
    vspeedx(0) = 0;
    vspeedy(0) = 1.8;
    vec ax(n+1);
    vec ay(n+1);


    for (int i=0;i<n;i++){
        d=i;
        angle(i)=(d/(n))*360; //Angle for 1 rotation
        ax(i) = ((-cos(angle(i))*GMsun)/(r*r)); //Acceleration in x - direction
        ay(i) = ((-sin(angle(i))*GMsun)/(r*r)); //Acceleration in y - direction

        // Euler forward method
        speedx(i+1) = speedx(i) + h*ax(i);
        speedy(i+1) = speedy(i) + h*ay(i);
        posx(i+1) = posx(i) + h*speedx(i);
        posy(i+1) = posy(i) + h*speedy(i);
        //cout << posx(i) << "\t" << posy(i) << "\t" << sqrt(posx(i)*posx(i)+posy(i)*posy(i))<<endl;

        //Verlet method
        vspeedx(i+1) = vspeedx(i)+h*ax(i);
        vspeedy(i+1) = vspeedy(i)+h*ay(i);
        vposx(i+1) = vposx(i) + h*vspeedx(i) + (0.5*h*h*ax(i));
        vposy(i+1) = vposy(i) + h*vspeedy(i) + (0.5*h*h*ay(i));
        //cout << vposx(i) << "\t" << vposy(i) << "\t" << sqrt(vposx(i)*vposx(i)+vposy(i)*vposy(i))<<endl;

    }

    return 0;
}
