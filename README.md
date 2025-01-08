# Cube3D
Inspired by Wolfenstein3D, this project goal was to render a "3D" dynamic view of a maze by casting rays. Wolfenstein3D, used "rays" to create a first-person shooter experience in a 2D environment, simulating a 3D view by projecting rays from the player's perspective to determine the visible walls and objects in the game. The "ray caster" gives the illusion of depth and perspective without using actual 3D models, allowing for fast and efficient rendering on early computer hardware.

![Untitledvideo-MadewithClipchamp1-ezgif com-video-to-gif-converter (1)](https://github.com/user-attachments/assets/3d0c190c-501a-4ca4-b63b-d7ba127c09ff)

## Contributors
- [Andres Madrid Ucha](https://github.com/andmadri): Ray-Caster Algorithm
- [Christian Rasche](https:://github.com/Chr-ss): Parsing, Texture-handling 

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

![image](https://github.com/user-attachments/assets/89dfa860-22cb-4936-8961-03d7cff3f259)


*What does this mean in terms of finding the end-point/obstacle that the ray hits?*

Well, the final distance of the ray is the sum of the step-size on x or y as you move through the grid. Let's take a look at the code:

```c
static void	ray_caster_step(t_data *data, t_raycaster *ray)
{
	if (ray->length[X] < ray->length[Y])
	{
		ray->r_pos[X] += ray->step[X];
		ray->final_distance = ray->length[X];
		ray->length[X] += ray->step_size[X];
		ray->wall_direction = EW;
	}
	else
	{
		ray->r_pos[Y] += ray->step[Y];
		ray->final_distance = ray->length[Y];
		ray->length[Y] += ray->step_size[Y];
		ray->wall_direction = NS;
	}
	if (data->map.map[ray->r_pos[Y]][ray->r_pos[X]] == '1')
	{
		ray->wall_found = true;
	}
}
```



The first if- and else-statement determines whether you need to move on the x- or y-axis accordingly. You can think of it as where does the ray hit the obstacle, on the x-axis first or on the y-axis. Let's go back to this image below, the color blue represents a wall.

![image](https://github.com/user-attachments/assets/e368dfad-cc31-43e1-980a-ec5b7cdff9ff)


Although the step size in the x-direction is shorter, causing us to begin moving right along the x-axis, there comes a point where the cumulative length of x (which adds the step size, **SX**, with each iteration) exceeds the length traveled along the y-axis. At this point, we switch from always checking the x-axis intersections to now check the y-intersections. This is where the ray hits an obstacle, and the final distance of the ray is determined by the length calculation on the y-step size, not the x-step size. This is the gist of the *DDA Algorithm*

In the code above:
1. **ray->pos[] += ray->step[]**: Step is either -1 or 1, this was calculated beforehand to determine in which direction the ray is moving; it is pretty straightforward. The ray->pos[] is later used to dereference the map and check if at that given position there is a wall.
2. **ray->final_distance = ray->length[]**: The final distance of the ray is always redefined until we hit the obstacle.
3. **ray->length[] += ray->step_size[]**: This is what will define the final distance, and with each iteration, we add the step_size that we calculated using **SX** adn **SY**

After the if-else statement, we get to check whether at the current **ray->pos[x]** and **ray->pos[y]** there is an obstacle/wall. Given the configuration of the map, '1' represents a wall and '0' a walkable space, therefore if at that given ray position on X and Y in the map equals '1', we turn the boolean ray->wall_found to true, which would stop the iteration.

To calculate the *line_height* of a wall, we simply scale the final_distance in terms of the heigth of the screen denoted by screen_y:

```c
ray.line_height = (float)milx->screen_y / (float)ray.final_distance;
```

### Useful Knowledge
#### Field of View (FOV)
The **Field of View** represent the visible area in front of the player, measured in degrees.

*Why is this important?*
- The FOV determines how wide the player's perspective is. A large FOV shows more of the environment but the objects can appear distored, while a smaller FOV narrows the range, giving a more zoomed-in feeling.
- It defines the spread of the rays that need to be cast.

#### Camera Plane
The **camera plane** help define the bounds of the FOV. It is a 2D line *perpendicular* to the player's direction.

*Why is the camera plane needed?*

- Determines how rays are spread across the FOV, from the leftmost edge of the screen to the righmost edge. Without it, all rays will follow the player's exact direction.

*What Does "Perpendicular* Mean?

*Perpendicular* means that two lines meet at a perfect 90-degree angle, like the corners of a square. If one line goes straight up and down (vertical), the perpendicular line will go left to right (horizontal).

To translate it to Cube3D, if the player is looking East/West, there needs to be an imaginary line that meets the "player's view" going North/South and vice versa.

*How is the Camera Plane Calculated?*

Let's assume the player's direction vector is $[dx, dy]$:

For two 2D vectors, being perpendicular means:
- Their **dot product** is zero:
  
$[dx, dy] * [-dy, dx] = dx * (-dy) + dy * dx = (-dx * dy) + (dy * dx) = 0$

Therefore the perpendicualr vector of $[dx, dy]$, has to be $[-dy, dx]$. This is because when you multiply these two vectors, they should give you zero. The only way to do this is by switching the x- and y-coordinate, and negating the y-coordinte.

```c
static void	ray_caster_init(t_raycaster	*ray, t_player *player)
{
	ft_bzero(ray, sizeof(t_raycaster)); //zero-out the raycaster struct
	player->plane[X] = -player->direct[Y]; //define the camera plane on x
	player->plane[Y] = player->direct[X]; //define the camera plane on y
	ray->r_start[X] = player->pos[X]; //the ray always starts where the player is
	ray->r_start[Y] = player->pos[Y];
	ray->plane_magnitude = tan((float)(FOV / 2) *RAD); //the length of the camera plane, times RAD because the tan() only accepts radians
}
```
*What is The Plane Magnitude & What is It for?*

The **camera plane** depends on the FOV. The wider the FOV, the larger the camera plane needs to be. It is derived from the tangent of half of the Field of View, which is the angle the player can see in their vision.

$Plane Magnitude = tan(\frac{FOV}{2})$

*Why Use Tangent?*

It connects the angle of the FOV to the width of the camera plane. Tangent helps calculate how far the left and right edges of the camera plane are based on the FOV angle.

![image](https://github.com/user-attachments/assets/d29c20e4-757c-45f3-bdae-3516d710b2aa)

If you draw a straight line through the player's view, you wull have two right-angle triangles. The *adjacent side* is the distance straight forward. The *opposite side* is half the width of the camera plane at a given distance. Therefore:

$tan(\frac{FOV}{2}) = \frac{Half Width of Camera Plane}{Distance Forward (1 unit)}

After rearranging:
$Half Width of Camera Plane = tan(\frac{FOV}{2})$

This ensures that the camera plane has a specific range related to the FOV!
The reason it is half the width of the camera plane has to do with how we are scaling the plane. The Plane scale ranges from -1 (left most edge), 0 (player's direction) and 1 (right most edge). 

The plane scale is done in this way, so that it can be used to determine the ray's direction, and given that West and North are -1 x and -1 y correspondingly, and South and East are 1 x and 1 y. We need to have a plane scale that also ranges from -1 to 1.

To calculate the plane scale:

```c
ray->plane_scale = (float)2 * ((float)x / (float)data->milx.screen_x) - (float)1;
```
To calculate the rays directions:

```c
ray->direction[X] = player->direct[X] + (player->plane[X] * ray->plane_magnitude) * ray->plane_scale;
ray->direction[Y] = player->direct[Y] + (player->plane[Y] * ray->plane_magnitude) * ray->plane_scale;
```
#### Step Direction & Inital Ray Length
The `step_direction()` function is critical for determining how the ray advances through the grid in the DDA algorithm. Depending on the direction of the ray, the ray steps in the positive or negative direction, because the ray travels through a grid, the goal is to determine which grid cell the ray enters next.

*What is the initial Length?*

One would think that the initial length (length_x and length_y are two separate lengths, which either one of them at the end becomes the final length of the ray) is the step size **SX** and **SY**. However, we do not always start from an 'integer space', meaning that the ray (player) does not always start at 1, 0 or -1


### Drawing The View

The sky and floor have the same measurement, because it is the space that is left from the space that the length of the wall/obstacle is going to take. To calculate it, you substract the height of the screen minus the length of the line height of the wall and then divide this by two.

```c
void	draw_background(t_data *data, t_minilx *milx, t_raycaster ray)
{
	int	height;
	int	i;

	height = (milx->screen_y - ray.line_height) / 2;
	i = 0;
	while (i <= height)
	{
		img_mlx_pixel_put(&milx->big, ray.x, i, data->map.c_col);
		img_mlx_pixel_put(&milx->big, ray.x, milx->screen_y - i, data->map.f_col);
		i++;
	}
}
```

The `img_mlx_pixel_put()`, takes as first parameter the image to draw to, then the x coordinate which is pointed by the x-coordinate of the ray, then the y coordinate and the last parameter is the color. The y-coordinate for the sky is obviously going to start from 0 (i) and move downwards (i++). For the floor it starts from the bottome and moves upwards.

Finally to draw the wall, you take half the screen minus half the height of the wall as the initial y-coordinate to start drawing. Loop the height of the wall and always check that the pixel you want to access is within the boundaries of your computer screen.

```c
void	img_mlx_pixel_put(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img->max_x && y < img->max_y)
	{
		dst = img->addr + (y * img->line_length + x * 4);
		*(unsigned int *)dst = color;
	}
}
```


## Useful Resources
For those who prefer reading:
https://lodev.org/cgtutor/raycasting.html

For those like me who are visual learners:
https://youtu.be/NbSee-XM7WA?si=4jTq7rchhQz859RB





