#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
<<<<<<< HEAD
#include <iostream>
#include <armadillo>
=======
#include <armadillo>
#include <string>

#include "planets.h"
>>>>>>> a4286acdf242b8c67aa75289ecb2e4688f64886c

using namespace std;
using namespace arma;

int main()

{
<<<<<<< HEAD
    int n=100;
    //double h=1./(n);
    vec angle = linspace<vec>(0,2*M_PI,n);

    vec x(n+1);
    vec y(n+1);
    vec vx(n+1);
    vec vy(n+1);
    vec ax(n+1);
    vec ay(n+1);
    vec radd(n+1);



    x(0)=1;
    y(0)=0;
    double r=1; //1 AU
    double h=1./n;

    vx(0)=0;
    vy(0)=1.8;
    radd(0)=1;

    double A=(4.0*M_PI*M_PI)/(r*r);



    for (int i=0;i<n;i++){


        ax(i)=-cos(angle(i))*A;
        vx(i+1) = vx(i) + h*ax(i);
        x(i+1) = x(i) + (h*vx(i+1));

        ay(i)=-sin(angle(i))*A;
        vy(i+1) = vy(i) + h*ay(i) ;
        y(i+1) = y(i) + (h*vy(i+1));

        radd(i+1)=sqrt(x(i+1)*x(i+1)+y(i+1)*y(i+1));



    }
    //cout << x << endl;
    //cout << y << endl;
    cout << radd << endl;




    /*
    int n=10;
    double h=1./(n+1);

    vec angle(n);
    vec x(n+1);
    vec y(n+1);
    x(0)=1;
    y(0)=0;
    double r=1; //1 AU
    double d;
    double pi;
    pi=4*atan(1);
    double GMsun = 4*pi*pi;
    vec vx(n+1);
    vx(0)=0;
    vec vy(n+1);
    vy(0)=0;



    for (int i=0;i<n;i++){
        d=i;
        angle(i)=(d/(n-1))*360;
        vx(i+1) = vx(i) - (h * GMsun*cos(angle(i))/(r*r));
        //x(i+1) = x(i) + (h*x(i+1));

        vy(i+1) = vy(i) - (h * GMsun*sin(angle(i))/(r*r));
        //posy(i+1) = y(i) + (h*vy(i+1));
        //cout << x(i+1) << "\t" << y(i+1) << "\t" << sqrt(x(i+1)*x(i+1)+y(i+1)*y(i+1))<<endl;


        x(i+1) = x(i) + h*vx(i) + (0.5*h*h*GMsun*x(i)/(r*r*r));
        y(i+1) = y(i) + h*vy(i) + (0.5*h*h*GMsun*y(i)/(r*r*r));

        cout << x(i+1) << "\t" << y(i+1) << "\t" << sqrt(x(i+1)*x(i+1)+y(i+1)*y(i+1))<<endl;

    }


=======
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

>>>>>>> a4286acdf242b8c67aa75289ecb2e4688f64886c
    return 0;
    */
}



