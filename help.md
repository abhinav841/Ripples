# About
**The following sections explain the salient parts of the program.**
## func()
The first thing that takes sight is ```func()``` - the surface function.

Value returned by ```func()``` (a float) is taken as the z-coordinate of the point (x, y) passed to it, i.e., the height of that point above/below the x-y plane.
Hence, ```func()``` defines the surface that is mostly spread across the horizon. There is another variable t for time, making the surface dynamic w.r.t time.

As a sidenote, I have found only periodic functions enjoyable - trigonometric and functions involving modulo.

## main()
**range and width**

range and size of the plot are initialised here.

```range``` is basically the area of the plot. For example, if ```range``` is set to ```6.5``` then plot will be of (0, 6.5) × (0, 6.5), i.e., a square of side length 6.5 units with its bottom left corner at the origin.

```width``` is for size of the plot; the number of characters in it. For example, if ```width``` is set to ```30``` (obviously an integer) then the plot will have (at most) 30 × 30 = 900 characters.

![](images/range_width.png)

One may ask -
> How can I get the plot for negative quadrants, for example, If I want the origin at the center of the plot?

For this, we can translate the surface by adding or subtracting appropriate values from x and y coordinates.
For example, let the surface function be sin(x + y² - t) and the range be 6. To shift the surface's origin to the centre of the plot,
I must subtract 3 from both x and y coordinates (why?). Hence, the desired function is sin((x-3) + (y-3)*(y-3) - t).