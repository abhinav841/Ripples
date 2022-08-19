#include <stdio.h>
#include <math.h>
#include <time.h>


float func(float x, float y, float t) {
	
	// defines the surface function z
	// as a function of x, y and time
	
	x -= 3; y -= 5;
	float d = sin(x*x + y*y - 5*t);
	return d;

}


void draw(float (*f)(float, float, float),
		  float, int, float [3], float);


int main() {
	
	float range; int width;
	
	///////////// User Input /////////////
	
	range = 07;          // range for plot
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
		
		draw(&func, range, width, light, t);
		for (i=0; i<=width; i++) {
			printf("\033[A");
			fflush(stdout);
		}
		
	}
	
	return 0;

}


float prjx(float (*f)(float, float, float),
		   float d, float x, float y,
		   float lit[3], float t) {
		   	
	// finds the intensity of reflection
	// or brightness at (x, y) by taking the
	// projection of (negative of) the light
	// vector on surface normal at (x, y)
	
	float dzx = ((*f)(x+d,y,t)-(*f)(x,y,t))/d;
	float dzy = ((*f)(x,y+d,t)-(*f)(x,y,t))/d;
	const float dzz = 1;
	
	// surface normal vector
	float nrm[3] = {-dzx, -dzy, +dzz};
	
	float mg1 = sqrt(nrm[0]*nrm[0] +
					 nrm[1]*nrm[1] +
					 nrm[2]*nrm[2]);
					 
	float mg2 = sqrt(lit[0]*lit[0] +
					 lit[1]*lit[1] +
					 lit[2]*lit[2]);
			
	return (-lit[0]*nrm[0] +
			-lit[1]*nrm[1] +
			-lit[2]*nrm[2])/
		    (mg1*mg2);
	
}


void draw(float (*f)(float, float, float),
		  float range, int width,
		  float light[3], float t) {
	
	// prints at each point a character as
	// per the brightness at that point
	
	// 1. storing values of f(x, y) at t
	int i, j;
	float values[width][width], r;
	float min = 0, max = 0;
	float c1 = range/width;
	
	for (i=0; i<width; i++)
		for (j=0; j<width; j++) {
			if ((r=prjx(f,c1,i*c1,j*c1,light,t)) > max)
				max = r;
	 	   else if (r < min)
	 	   	min = r;
	 	   values[i][j] = r;
		}
	 
	// 2. plotting the points
	char shades[] = " .:-+=*%@#";
	float c2 = (sizeof(shades)-2.)/(max-min);
	
	for (j=width-1; j+1; j--) {
		for (i=0; i<width; i++)
			printf(" %c",shades[(int)round((values[i][j]-min)*c2)]);
		printf("\n");
	}

}