/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:38:21 by crasche           #+#    #+#             */
/*   Updated: 2024/10/09 17:09:34 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	destroy_images(t_data *data, t_minilx *milx)
{
	if (milx->big.img)
		mlx_destroy_image(milx->mlx, milx->big.img);
	if (data->map.img_n.img)
		mlx_destroy_image(milx->mlx, data->map.img_n.img);
	if (data->map.img_s.img)
		mlx_destroy_image(milx->mlx, data->map.img_s.img);
	if (data->map.img_e.img)
		mlx_destroy_image(milx->mlx, data->map.img_e.img);
	if (data->map.img_w.img)
		mlx_destroy_image(milx->mlx, data->map.img_w.img);
	if (BONUS && milx->mini.img)
		mlx_destroy_image(milx->mlx, milx->mini.img);
}

int	finish_mlx(t_data *data)
{
	t_minilx	milx;

	milx = data->milx;
	if (milx.mlx)
		destroy_images(data, &milx);
	if (milx.mlx && milx.mlx_window)
		mlx_destroy_window(milx.mlx, milx.mlx_window);
	if (milx.mlx)
		mlx_destroy_display(milx.mlx);
	if (milx.mlx)
		freenull((void **) &milx.mlx);
	free_all(data);
	exit(0);
}
