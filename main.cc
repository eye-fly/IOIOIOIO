#include <iostream>
#include <numbers>
#include <cmath>
#include "structs.h"
#include "points.h"

double fov;
double distanceToPlane;
double planeSize[2];
int resolution[2];
double dd = 1;

Point fromScreenToPlane(int x, int y){

    Vector v( x/resolution[0]*planeSize[1], y/resolution[1]*planeSize[0],0 );
    v+=Vector( -planeSize[1]/2, -planeSize[0]/2, -distanceToPlane );
    // Matrix r  = 

    rotateMatrixY(std::numbers::pi/2)*v;
    
    return Point(dd*x*planeSize[0]/resolution[0], dd*y*planeSize[1]/resolution[1]);
} 

int main(int argc, char *argv[])
{
        int x,y;
        Point p;
    resolution[0]= 1280;
    resolution[1] = 720;

    fov = std::numbers::pi/2;

    distanceToPlane = 90;
    planeSize[0] = std::tan(fov/2)*distanceToPlane*2;
    planeSize[1] = planeSize[0]* (dd*resolution[1]/resolution[0]);

    std::cout<<planeSize[0]<<" "<<planeSize[1]<<"\n";
    while (1)
    {
        std::cin>>x>>y;
        p = fromScreenToPlane(x,y);
        std::cout<<p.x<<" "<<p.y<<"\n";
    }
    
}