#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()

{
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


    return 0;
    */
}



