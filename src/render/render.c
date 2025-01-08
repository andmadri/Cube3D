/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:38:21 by crasche           #+#    #+#             */
/*   Updated: 2024/10/08 13:08:50 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	render(t_data *data)
{
	if (data->keys.exit)
		finish_mlx(data);
	key_hook_move(data);
	key_hook_strafe(data);
	key_hook_turn(data);
	if (BONUS)
		draw_minimap(data);
	ray_caster(data, &data->milx);
	mlx_put_image_to_window(data->milx.mlx, data->milx.mlx_window, \
		data->milx.big.img, 0, 0);
	if (BONUS)
		mlx_put_image_to_window(data->milx.mlx, data->milx.mlx_window, \
			data->milx.mini.img, 5, 5);
	return (0);
}
