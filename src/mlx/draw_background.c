/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_background.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: andmadri <andmadri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/08 20:38:21 by crasche       #+#    #+#                 */
/*   Updated: 2024/10/08 14:53:40 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	draw_background(t_data *data, t_minilx *milx, t_raycaster ray)
{
	int	height;
	int	i;

	height = (milx->screen_y - ray.line_height) / 2;
	i = 0;
	while (i <= height)
	{
		if (BONUS && !CRAZY)
		{
			img_mlx_pixel_put(&milx->big, ray.x, i, \
				color_fraction(data->map.c_col, WHITE, (fmin((float)i \
				/ (milx->screen_y / 3), 1.0))));
			img_mlx_pixel_put(&milx->big, ray.x, milx->screen_y - i, \
				color_fraction(data->map.f_col, WHITE, (fmin((float)i \
				/ (milx->screen_y / 2.2), 1.0))));
		}
		else if (!CRAZY)
		{
			img_mlx_pixel_put(&milx->big, ray.x, i, data->map.c_col);
			img_mlx_pixel_put(&milx->big, ray.x, milx->screen_y - i, \
				data->map.f_col);
		}
		i++;
	}
}
