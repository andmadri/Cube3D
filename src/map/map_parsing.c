/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:26:53 by crasche           #+#    #+#             */
/*   Updated: 2024/10/09 17:08:51 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	map_parse_meta_open_tex(t_data *data)
{
	int	temp;

	temp = open(data->map.n_tex, O_RDONLY);
	if (temp >= 0)
		close(temp);
	else
		error("Error, unable to open NORTH texture.", data);
	temp = open(data->map.e_tex, O_RDONLY);
	if (temp >= 0)
		close(temp);
	else
		error("Error, unable to open EAST texture.", data);
	temp = open(data->map.s_tex, O_RDONLY);
	if (temp >= 0)
		close(temp);
	else
		error("Error, unable to open SOUTH texture.", data);
	temp = open(data->map.w_tex, O_RDONLY);
	if (temp >= 0)
		close(temp);
	else
		error("Error, unable to open WEST texture.", data);
}

static void	map_parse_wallcheck(t_data *data, char **map, int y, int x)
{
	if (y == 0 || (y && map[y - 1][x] == ' '))
		error("Error, unclosed map", data);
	if (x == 0 || (x && map[y][x - 1] == ' '))
		error("Error, unclosed map", data);
	if (!map[y + 1] || (map[y + 1] && map[y + 1][x] == ' '))
		error("Error, unclosed map", data);
	if (map[y][x + 1] == '\0' || map[y][x + 1] == ' ')
		error("Error, unclosed map", data);
}

static void	map_parse_player(t_data *data, char **map, int x, int y)
{
	if (data->player.pos[X] || data->player.pos[Y])
		error("Error, duplicate player position.", data);
	data->player.pos[X] = x + 0.5;
	data->player.pos[Y] = y + 0.5;
	if (map[y][x] == 'N')
		data->player.direct[Y] = -1;
	else if (map[y][x] == 'S')
		data->player.direct[Y] = 1;
	else if (map[y][x] == 'E')
		data->player.direct[X] = 1;
	else if (map[y][x] == 'W')
		data->player.direct[X] = -1;
	map[y][x] = '0';
	map_parse_wallcheck(data, map, y, x);
}

static void	map_parse_meta(t_data *data)
{
	if (!data->map.n_tex)
		error("Error, missing north texture", data);
	if (!data->map.e_tex)
		error("Error, missing east texture", data);
	if (!data->map.s_tex)
		error("Error, missing south texture", data);
	if (!data->map.w_tex)
		error("Error, missing west texture", data);
	if (!data->map.color.f_col)
		error("Error, missing floor color", data);
	if (!data->map.color.c_col)
		error("Error, missing ceiling color", data);
	map_parse_meta_open_tex(data);
}

void	map_parse(t_data *data, char **map)
{
	int	y;
	int	x;

	y = 0;
	map_parse_meta(data);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				map_parse_wallcheck(data, map, y, x);
			else if (map[y][x] == 'N' || map[y][x] == 'E' \
				|| map[y][x] == 'S' || map[y][x] == 'W')
				map_parse_player(data, map, x, y);
			else if (map[y][x] != '1' && map[y][x] != ' ')
				error("Error, invalid char in map", data);
			x++;
		}
		y++;
	}
	if (!data->player.pos[X] || !data->player.pos[Y])
		error("Error, missing player position", data);
}
