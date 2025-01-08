/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:31:41 by crasche           #+#    #+#             */
/*   Updated: 2024/10/09 14:44:09 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	map_color_array_nbr(t_data *data, char **array)
{
	int	i;
	int	c;

	i = 0;
	while (array && array[i])
	{
		c = 0;
		while (ft_isdigit(array[i][c]))
			c++;
		if (array[i][c] != '\0')
			error("Error, invalid color value.", data);
		i++;
	}
}

static void	map_color_array_size(t_data *data, char **c_split, char **f_split)
{
	int	i;

	i = 0;
	while (c_split && c_split[i])
		i++;
	if (i != 3)
		error("Error, ceiling color invalid.", data);
	i = 0;
	while (f_split && f_split[i])
		i++;
	if (i != 3)
		error("Error, floor color invalid.", data);
}

static void	map_color_rgb_convert(t_data *data, t_color *color)
{
	color->c[R] = ft_atoi_rgb(color->c_split[R]);
	color->c[G] = ft_atoi_rgb(color->c_split[G]);
	color->c[B] = ft_atoi_rgb(color->c_split[B]);
	if (color->c[R] < 0 || color->c[R] > 255 || color->c[G] < 0 || \
		color->c[G] > 255 || color->c[B] < 0 || color->c[B] > 255)
		error("Error, ceiling color invalid.", data);
	color->f[R] = ft_atoi_rgb(color->f_split[R]);
	color->f[G] = ft_atoi_rgb(color->f_split[G]);
	color->f[B] = ft_atoi_rgb(color->f_split[B]);
	if (color->f[R] < 0 || color->f[R] > 255 || color->f[G] < 0 || \
		color->f[G] > 255 || color->f[B] < 0 || color->f[B] > 255)
		error("Error, floor color invalid.", data);
}

static void	map_color_seperator(t_data *data, char *color)
{
	int	i;
	int	seperator;

	i = 0;
	seperator = 0;
	while (color && color[i])
	{
		if (color[i] == ',')
			seperator++;
		i++;
	}
	if (seperator != 2)
		error("Error, invalid color.", data);
}

void	map_color(t_data *data, t_color *color)
{
	map_color_seperator(data, color->c_col);
	map_color_seperator(data, color->f_col);
	color->c_split = ft_split(color->c_col, ',');
	color->f_split = ft_split(color->f_col, ',');
	if (!color->c_split || !color->f_split)
		error("Error, malloc color split.", data);
	map_color_array_size(data, color->c_split, color->f_split);
	map_color_array_nbr(data, color->c_split);
	map_color_array_nbr(data, color->f_split);
	map_color_rgb_convert(data, color);
	data->map.c_col = create_trgb(0, color->c[R], color->c[G], color->c[B]);
	data->map.f_col = create_trgb(0, color->f[R], color->f[G], color->f[B]);
}
