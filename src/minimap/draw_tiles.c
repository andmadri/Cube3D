/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_tiles.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/08 20:38:21 by crasche       #+#    #+#                 */
/*   Updated: 2024/10/03 16:13:14 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	draw_minimap_tiles_draw(t_data *data, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = data->player.pos[X] * MM_TILE_SIZE - (MINI_MAP / 2);
	map_y = data->player.pos[Y] * MM_TILE_SIZE - (MINI_MAP / 2);
	if (((float) map_x + x) / MM_TILE_SIZE >= 0 && ((float )map_y + y) / \
		MM_TILE_SIZE >= 0 && (map_x + x) / MM_TILE_SIZE < data->map.x_max \
		&& (map_y + y) / MM_TILE_SIZE < data->map.y_max)
	{
		if (data->map.map[(map_y + y) / MM_TILE_SIZE][(map_x + x) / \
		MM_TILE_SIZE] == '1')
			img_mlx_pixel_put(&(data->milx.mini), x, y, MM_WALL_COLOR);
		else if (data->map.map[(map_y + y) / MM_TILE_SIZE][(map_x + x + 1) \
			/ MM_TILE_SIZE] == '1')
			img_mlx_pixel_put(&(data->milx.mini), x, y, MM_WALL_COLOR);
		else if (data->map.map[(map_y + y) / MM_TILE_SIZE][(map_x + x) \
			/ MM_TILE_SIZE] == '0')
			img_mlx_pixel_put(&(data->milx.mini), x, y, MM_FLOOR_COLOR);
	}
}

void	draw_minimap_tiles(t_data *data)
{
	int	x;
	int	y;

	y = MM_BORDER_SIZE;
	while (y <= MINI_MAP - MM_BORDER_SIZE)
	{
		x = MM_BORDER_SIZE;
		while (x <= MINI_MAP - MM_BORDER_SIZE)
		{
			draw_minimap_tiles_draw(data, x, y);
			x++;
		}
		y++;
	}
}
