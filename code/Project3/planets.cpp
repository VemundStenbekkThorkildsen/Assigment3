#include "planets.h"

planets::planets(){
    newHeight = 0;
    newWeight = 0.0;
}

planets::planets(string name, int n, double r, double weight){

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
    newName = name;
    newHeight = height;
    newWeight = weight;

}

string planets::getName() const{
    return newName;
}

