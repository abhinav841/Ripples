// The following are my favourite functions


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
    k = 7;
    dx = r*sin(k*a-3*t)*sin(k*a)+r;
    dy = r*sin(k*a-3*t)*cos(k*a)+r;
    x -= dx;
    y -= dy;
    d = sin(x*x + y*y - 3*t);

    /* on applying the idea of spiral equation
     * i got another equation for wavy_ripple:
     * z = sin(r - sin(k*a))
     * where, r = sqrt(x² + y²)
              a = tan^-1(y/x)
              k is an integer
     */

    return d;

}


float propeller(float x, float y, float t) {
	
	// range may be taken 05
	x -= 3; y -= 3;
	float a, r, d;
	a = atan2(y, x);
	r = sqrt(x*x + y*y);
	d = 0.3*sin(r - 20*a - t*t) - 0.3*sin(r*r);
	
	return d;

}
