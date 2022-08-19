# Ripples

The program attempts to visualise a given function of the form z = f(x, y, t).
Display elements are ASCII characters.
The program uses only a set of ten characters: " .:-+=*%@#", more characters will result in better details.
Frame by frame, it displays the surface illuminated by a light source for that instant of time.
This printing task is done by draw(). It prints the surface character by character where the choice of character
depends upon the brightness at that point on the surface. But draw() itself doesn't evaluate the brightness at
each point it is prjx() that does the job.
