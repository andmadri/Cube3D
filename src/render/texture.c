/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/08 20:38:21 by crasche       #+#    #+#                 */
/*   Updated: 2024/10/09 14:29:39 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static int	texture_cord(t_raycaster *ray, int x, int y, float prec)
{
	if (y != (int)(ray->img->max_y * prec))
	{
		y = (int)ray->img->max_y * prec;
		ray->col = img_get_pixel_color(ray->img, x, y);
		return (y);
	}
	return (y);
}

static void	draw_texture_lines(t_data *data, int s_y)
{
	int			offset;
	int			c_x;
	int			c_y;
	t_raycaster	ray;

	ray = data->ray;
	c_y = -1;
	offset = 0;
	if (s_y < 0)
		offset = -s_y;
	c_x = data->map.img_n.max_x * ray.texture_perc;
	while (offset < ray.line_height && (s_y + offset) < data->milx.screen_y)
	{
		c_y = texture_cord(&ray, c_x, c_y, (float)offset / ray.line_height);
		if (CRAZY)
			ray.col = color_fraction(ray.col, WHITE, \
				fmax(ray.final_distance, 1.1));
		if (BONUS)
			img_mlx_pixel_put(&data->milx.big, ray.x, s_y + offset, \
				color_fraction(ray.col, WHITE, \
				fmin(ray.final_distance / 6, 1.0)));
		else
			img_mlx_pixel_put(&data->milx.big, ray.x, s_y + offset, ray.col);
		offset++;
	}
}

static void	decide_texutre_ns(t_data *data, t_raycaster *ray)
{
	if (ray->intersect[Y] < data->player.pos[Y])
	{
		ray->img = &data->map.img_s;
		ray->texture_perc = ray->intersect[X] - (int)ray->intersect[X];
	}
	else
	{
		ray->img = &data->map.img_n;
		ray->texture_perc = (float)1 - (ray->intersect[X] - \
			(int)ray->intersect[X]);
	}
}

static void	decide_texutre_ew(t_data *data, t_raycaster *ray)
{
	if (ray->intersect[X] > data->player.pos[X])
	{
		ray->img = &data->map.img_w;
		ray->texture_perc = ray->intersect[Y] - (int)ray->intersect[Y];
	}
	else
	{
		ray->img = &data->map.img_e;
		ray->texture_perc = (float)1 - (ray->intersect[Y] - \
			(int)ray->intersect[Y]);
	}
}

void	draw_texture(t_data *data)
{
	t_raycaster	*ray;

	ray = &data->ray;
	if (ray->wall_direction == NS)
	{
		decide_texutre_ns(data, ray);
	}
	else if (ray->wall_direction == EW)
	{
		decide_texutre_ew(data, ray);
	}
	draw_texture_lines(data, data->milx.screen_y / 2 - \
		round(ray->line_height / 2));
}
