// The following are my favourite functions


float spiral(float x, float y, float t) {

    // range may be taken 07
    x -= 2.5; y -= 2.5;
    float a, r, d;
    a = atan2(y, x);
    r = (x*x + y*y);   // sqrt(r) for uniform spiral
    d = 2*sin(r - a - t*t);  // t*t for accelerating rotation

    return d;

}


float wavy_ripple(float x, float y, float t) {

    // range may be taken 05
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


float pendulum(float x, float y, float t) {
	
	// range may be taken 10
	t *= 2;
	x -= 5;
	y -= 17;
	
	// rotating the whole plane
	// about the origin back and forth
	float r, a, X, Y, l = 15;
	r = sqrt(x*x + y*y);
	a = atan2(y, x);
	X = r*cos(0.2*sin(t) + a);
	Y = r*sin(0.2*sin(t) + a);
	
	// creating pendulum and string
	a = X*X + pow(Y+l, 2);
	if (a <= 2)
		return sqrt(2 - a);
	else if ((X*X <= 0.1) && (Y > -l))
		return sqrt(0.1 - X*X);
	return sqrt(-1);

}
