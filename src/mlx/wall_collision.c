/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wall_collision.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: andmadri <andmadri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 19:21:38 by andmadri      #+#    #+#                 */
/*   Updated: 2024/10/09 14:36:41 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	collision_ray_init(t_data *data, t_raycaster *ray, float x, float y)
{
	ft_bzero(ray, sizeof(t_raycaster));
	ray->r_start[X] = data->player.pos[X];
	ray->r_start[Y] = data->player.pos[Y];
	ray->r_pos[X] = ray->r_start[X];
	ray->r_pos[Y] = ray->r_start[Y];
	ray->direction[X] = x;
	ray->direction[Y] = y;
	ray->step_size[X] = fabsf(1 / ray->direction[X]);
	ray->step_size[Y] = fabsf(1 / ray->direction[Y]);
	ray->wall_found = false;
	step_direction(ray);
}

static int	collision(t_data *data, float dir_x, float dir_y)
{
	t_raycaster	ray;

	collision_ray_init(data, &ray, dir_x, dir_y);
	while (ray.final_distance < (STEP_SIZE * 6))
	{
		if (ray.length[X] < ray.length[Y])
		{
			ray.r_pos[X] += ray.step[X];
			ray.final_distance = ray.length[X];
			ray.length[X] += ray.step_size[X];
		}
		else
		{
			ray.r_pos[Y] += ray.step[Y];
			ray.final_distance = ray.length[Y];
			ray.length[Y] += ray.step_size[Y];
		}
		if (data->map.map[ray.r_pos[Y]][ray.r_pos[X]] == '1')
			break ;
	}
	if (ray.final_distance < (STEP_SIZE * 2))
		return (1);
	else
		return (0);
}

int	is_not_wall(t_data *data, float vx, float vy, int direction)
{
	if (direction == FORWARD && collision(data, vx, vy))
		return (0);
	if (direction == BACKWARD && collision(data, vx, vy))
		return (0);
	if (direction == LEFT && collision(data, vx, vy))
		return (0);
	if (direction == RIGHT && collision(data, vx, vy))
		return (0);
	return (1);
}
