/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:49:00 by crasche           #+#    #+#             */
/*   Updated: 2024/10/09 17:09:05 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

// mlx_get_screen_size(milx->mlx, &milx->screen_x, &milx->screen_y);
int	init_mlx_struct(t_data *data, t_minilx *milx)
{
	milx->mlx = mlx_init();
	if (!milx->mlx)
		return (free_all(data), EXIT_FAILURE);
	milx->screen_x = 1280;
	milx->screen_y = 720;
	milx->mlx_window = mlx_new_window(milx->mlx, milx->screen_x, \
	milx->screen_y, "CUBE3D");
	if (!milx->mlx_window)
	{
		finish_mlx(data);
		return (EXIT_FAILURE);
	}
	init_image(data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (argc <= 1)
		error("Missing map.", &data);
	else if (argc > 2)
		error("To many arguments.", &data);
	data.map.map_read.filename = argv[1];
	if (BONUS)
		data.keys.mouse = true;
	map_init(&data, &data.map);
	map_parse(&data, data.map.map);
	if (init_mlx_struct(&data, &data.milx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	hooks_mlx(&data);
	mlx_loop(data.milx.mlx);
	return (0);
}
