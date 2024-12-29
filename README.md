# CUBE3D
Inspired by Wolfenstein3D, this project goal was to render a "3D" dynamic view of a maze by casting rays. Wolfenstein3D, used "rays" to create a first-person shooter experience in a 2D environment, simulating a 3D view by projecting rays from the player's perspective to determine the visible walls and objects in the game. The "ray caster" gives the illusion of depth and perspective without using actual 3D models, allowing for fast and efficient rendering on early computer hardware.

![Untitledvideo-MadewithClipchamp1-ezgif com-video-to-gif-converter (1)](https://github.com/user-attachments/assets/3d0c190c-501a-4ca4-b63b-d7ba127c09ff)

## Build Instructions
First git clone it in your root directory with the name CUBE3D
```bash
git clone git@github.com:andmadri/CUBE3D.git CUBE3D
```

Afterwards move to CUBE3D and run make all, once it's done, you need the executable `cub3D` and a map, all available maps are inside the maps/ folder:
```bash
cd CUBE3D
make all
...
./cub3D maps/long.cub
```

## Maps
The program is design to parse a specific configuration in terms of how maps should be displayed

## Ray Caster Algorithm
The point of the ray caster algorithm is to determine the distance between the player's position and an obstacle whether this is a wall or an object. The length of this ray, will help in rendering the maze view. The most computationally efficient way to achieve this is by checking every point on the grid where the ray has intersected with either the x- or y-axis. One of these intersections will represent the obstacle the ray is meant to detect.

![image](https://github.com/user-attachments/assets/379e2ba1-a290-4d40-b20d-989b72a26f01)

There are two values that need to be defined before applying the algorithm:
1. The player's position or where the ray starts.
2. The direction where the ray is going to end.

To calculate the length of the ray, Trigonometry comes in handy. Think of the ray length as the hypotenuse of a right-angle triangle. Now, the main question to have in mind is, *For a movement of one unit in the x-axis or y-axis, how far have we moved along the ray (hypotenuse)?*

The hypotenuse formula helps calculate the **length of the ray** when it takes a single step along the grid lines(x or y). One thing to consider is that the step sizes between each intersection points on x and y remain constant for all points on the x-axis, as well as for all points on the y-axis.

The hypotenuse *h* is defined as:

$h = \sqrt{x^2 + y^2}$

Apart from the hypotenuse, the formula of the slope of the ray is needed. This formula accounts for **directional proportionality**. 

Imagine you want to cross from one corner of a room to the other. The floor is made of tiles, yet you are only allowed to walk along the edges of the tiles and therefore you cannot 
- **The hypotenuse formula** helps you figure out the straight-line distance from one corner of the room to the other.
- **The slope** tells you how much you need to move up (y-axis) or to the side (x-axis) for every step you take.

If you only used the hypotenuse formula, you could know how far away the corner of the room is, but you wouldn't know exactly how to get there as you can only walk along the edges of the tiles.

The slope *m* is defined as:

$m = \frac{dy}{dx}$

This means that for every **unit step** you take in the x-axis, the y-axis changes by *m* times that amount.

When stepping in the x-direction:
- You take one unit step in x, which means (**dx = 1**).
- The corresponding y-change is (**dy = m**) because (**m = dy / dx**), then (**m = dy / 1**), we replaced the dx with 1, so (**m = dy = dy/x**). The value of dy is the same as the value of the slope.
- Therefore the step size on each x intersection using now the hypotenuse formula is:

$sx = \sqrt{1^2 + \frac{dy}{dx}^2}$

When stepping in the y-direction:
- You take one unit step in y, which means (**dy = 1**).
- The corresponding x-change is (**dx = 1 / m**) because (**m = 1 / dx**), then (**dx * m = 1**), so (**dx = 1 / m**) which is reciprocal to (**dx = dx / dy**). This makes sence because we want to know how much x is changing in terms of y.

$sy = \sqrt{1^2 + \frac{dx}{dy}^2}$

Now with the step size of each axis, we can apply the algorithm. The algorithm states that you should move on the x- or y-axis depending on which ever step size is smaller. In the image bellow, we can see that the step size of x (**SX**) is smaller than the step size of (**SY**), therefore we will move on the x-axis afterwards.

![image](https://github.com/user-attachments/assets/038e363f-226b-4056-a87d-aa5a83acc8c2)

*What does this mean in terms of finding the end-point/obstacle that the ray hits?*
Well, the final distance of the ray is the sum of the step-size on x or y as you move through the grid. Let's take a look at the code:





## Textures

## Useful Resources
For those who prefer reading:
https://lodev.org/cgtutor/raycasting.html

For those like me who are visual learners:
https://youtu.be/NbSee-XM7WA?si=4jTq7rchhQz859RB





