// The following are my favourite functions.
// I did not find them accidently, I had to
// derive each one of them.


float spiral(float x, float y, float t) {

    // range may be taken 07
    x -= 2.5; y -= 2.5;
    float a, r, d;
    a = atan2(y, x)-5*t;
    r = sqrt(x*x + y*y);   // remove sqrt for uniform spiral
    d = 2*sin(r - a + t);  // (-t) to reverse the rotation

    return d;

}


float wavy_ripple(float x, float y, float t) {

    // range may be taken 07
    x -= 2.5; y -= 2.5;
    float a, r, k, dx, dy, d;
    a = atan2(y, x);
    r = 0.3/(sqrt(x*x + y*y)+1);
    k = 15;
    dx = r*sin(k*a-3*t)*sin(a)+r;
    dy = r*sin(k*a-3*t)*cos(a)+r;
    x -= dx;
    y -= dy;
    d = sin(x*x + y*y - 5*t);

    /* on applying the idea of spiral equation
     * i got another equation for wavy_ripple:
     * z = sin(r - sin(k*a))
     * where, r = sqrt(x² + y²)
              a = tan^-1(y/x)
              k is an integer
     */

    return d;

}
