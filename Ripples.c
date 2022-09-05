#include <stdio.h>
#include <math.h>
#include <time.h>
#include "surface.h"


float ripple(float x, float y, float t) {

    // defines the surface function z
    // as a function of x, y and time

    x -= 2.3; y -= 2.5;
    float d = sin(x*x + y*y - 5*t);
    return d;

}


void draw(float (*f)(float, float, float), float, int, float [3], float);


int main() {

    float (*func)(float, float, float) = &ripple;
    float range; int width;

    ///////////// User Input /////////////

    range = 06;          // range for plot
    width = 60;          // size on screen

    //////////////////////////////////////

    // direction vector for light source
    float light[3];

    // t is the time variable for both
    // light source and surface function
    float t, _; int i;
    const clock_t t0 = clock();

    while (1) {

        t = ((float)(clock()-t0))/CLOCKS_PER_SEC;

        // defines how the direction of
        // light changes with time
        _ = sin(t/3)+1;
        light[0] = _*sin(t);
        light[1] = _*cos(t);
        light[2] = -2+_;

        draw(func, range, width, light, t);

        // to clear the screen for next frame
        for (i=0; i<=width; i++) {
            printf("\033[A");
            fflush(stdout);
            }

        }

        return 0;

}


float prjx(float (*f)(float, float, float), float d, float x, float y, float lit[3], float t) {

    // finds the intensity of reflection or
    // brightness at (x, y), which is given
    // by the z component of the light reflected
    // by the small surface area at (x, y).

    float dzx = ((*f)(x+d,y,t)-(*f)(x,y,t))/d;
    float dzy = ((*f)(x,y+d,t)-(*f)(x,y,t))/d;
    float dsq = d*d;

    // surface normal vector
    float nrm[3] = {-dsq*dzx, -dsq*dzy, +dsq};

    float dot =  lit[0]*nrm[0] +
                 lit[1]*nrm[1] +
                 lit[2]*nrm[2];

    if (dot > 0) return 0;

    float _a_ = (nrm[0]*nrm[0] +
                 nrm[1]*nrm[1] +
                 nrm[2]*nrm[2]);

    float _l_ = (lit[0]*lit[0] +
                 lit[1]*lit[1] +
                 lit[2]*lit[2]);

    return (_a_*_a_*lit[2] -
            2*nrm[2]*dot)/(sqrt(_l_)*_a_);

}


void draw(float (*f)(float, float, float), float range, int width, float light[3], float t) {

    // prints at each point a character as
    // per the brightness at that point

    // 1. storing values of f(x, y) at t
    int i, j;
    float values[width][width];
    float c1 = range/width;

    for (i=0; i<width; i++)
        for (j=0; j<width; j++) {
            values[i][j] = prjx(f,c1,i*c1,j*c1,light,t);
        }

    // 2. plotting the points
    char shades[] = " .:-+=*%@#";
    float c2 = (sizeof(shades)-2)/2.;

    for (j=width-1; j+1; j--) {
        for (i=0; i<width; i++)
            printf(" %c",shades[(int)round(values[i][j]*c2)]);
        printf("\n");
    }

}
