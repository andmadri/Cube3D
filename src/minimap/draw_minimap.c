/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_minimap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: andmadri <andmadri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/08 20:38:21 by crasche       #+#    #+#                 */
/*   Updated: 2024/10/03 16:13:27 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	draw_minimap_clear(t_minilx *milx)
{
	int	x;
	int	y;

	y = MM_BORDER_SIZE;
	while (y <= MINI_MAP - MM_BORDER_SIZE)
	{
		x = MM_BORDER_SIZE;
		while (x <= MINI_MAP - MM_BORDER_SIZE)
		{
			img_mlx_pixel_put(&milx->mini, x, y, MM_VOID_COLOR);
			x++;
		}
		y++;
	}
}

static void	draw_fov_lines(t_mlx_img *img, float vx, float vy)
{
	float	magnitude;
	float	x;
	float	y;
	int		i;

	magnitude = sqrt(vx * vx + vy * vy);
	vx /= magnitude;
	vy /= magnitude;
	x = MINI_MAP / 2;
	y = MINI_MAP / 2;
	i = 0;
	while (i < VIEW_DISTANCE)
	{
		if (img_get_pixel_color(img, (int)x, (int)y) == MM_WALL_COLOR)
			return ;
		img_mlx_pixel_put(img, (int)x, (int)y, color_fraction(MM_VIEW_COLOR, \
			MM_FLOOR_COLOR, ((float)i / (float)VIEW_DISTANCE)));
		x += vx;
		y += vy;
		i++;
	}
}

static void	draw_minimap_view(t_data *data, t_minilx *milx)
{
	t_player	player;
	float		vx;
	float		vy;
	int			i;

	i = -(FOV / 2);
	player = data->player;
	while (i < (FOV / 2))
	{
		vx = player.direct[X] * cos(i * RAD) - player.direct[Y] * sin(i * RAD);
		vy = player.direct[X] * sin(i * RAD) + player.direct[Y] * cos(i * RAD);
		draw_fov_lines(&milx->mini, vx, vy);
		i++;
	}
}

int	draw_minimap(t_data *data)
{
	t_minilx	*milx;

	milx = &data->milx;
	draw_minimap_clear(milx);
	draw_minimap_tiles(data);
	draw_minimap_view(data, milx);
	draw_minimap_player(milx, MM_PLAYER_SIZE);
	return (0);
}
