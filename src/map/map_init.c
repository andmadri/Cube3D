/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmadri <andmadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:28:42 by crasche           #+#    #+#             */
/*   Updated: 2024/10/09 15:06:20 by andmadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	map_fill(t_data *data, t_map *map)
{
	int		i;
	char	*old;

	i = 0;
	while (map->map[i])
	{
		if ((int) ft_strlen(map->map[i]) != map->x_max)
		{
			old = map->map[i];
			map->map[i] = ft_calloc(map->x_max + 1, sizeof(char));
			if (!map->map[i])
			{
				freenull((void **) &old);
				error("Error, malloc map_fill", data);
			}
			ft_memset(map->map[i], ' ', map->x_max);
			ft_strlcpy(map->map[i], old, ft_strlen(old) + 1);
			map->map[i][ft_strlen(old)] = ' ';
			freenull((void **) &old);
		}
		i++;
	}
}

static void	map_meta(t_data *data, t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (!ft_strncmp(map->map[i], "NO ", 3))
			map_meta_copy(data, map->map[i], &map->n_tex, 2);
		else if (!ft_strncmp(map->map[i], "SO ", 3))
			map_meta_copy(data, map->map[i], &map->s_tex, 2);
		else if (!ft_strncmp(map->map[i], "WE ", 3))
			map_meta_copy(data, map->map[i], &map->w_tex, 2);
		else if (!ft_strncmp(map->map[i], "EA ", 3))
			map_meta_copy(data, map->map[i], &map->e_tex, 2);
		else if (!ft_strncmp(map->map[i], "F ", 2))
			map_meta_copy(data, map->map[i], &map->color.f_col, 1);
		else if (!ft_strncmp(map->map[i], "C ", 2))
			map_meta_copy(data, map->map[i], &map->color.c_col, 1);
		else if (!ft_strncmp(map->map[i], "\0", 1))
			;
		else
			break ;
		map_clear_line(data, map, i);
	}
}

static void	map_read(t_data *data, t_map *map)
{
	char	buf[READBUF + 1];
	int		readbyt;
	char	*old;

	readbyt = 1;
	while (readbyt > 0)
	{
		ft_bzero(buf, READBUF + 1);
		readbyt = read(map->map_read.fd, buf, READBUF);
		if (readbyt == -1)
			error ("Error, read error for map", data);
		old = map->map_read.read;
		if (!map->map_read.read)
			map->map_read.read = ft_strdup(buf);
		else
			map->map_read.read = ft_strjoin(map->map_read.read, buf);
		free(old);
		if (!map->map_read.read)
			error ("Error, read malloc", data);
	}
}

static void	map_nl_check(t_data *data, t_map *map)
{
	int		i;
	bool	inside_map;

	i = 0;
	inside_map = false;
	if (!map->map_read.read)
		error("Error, map_read.", data);
	while (map->map_read.read[i])
	{
		if (!inside_map && map->map_read.read[i] == '\n' \
			&& map->map_read.read[i + 1] == '1')
			inside_map = true;
		if (inside_map && map->map_read.read[i] == '\n' \
			&& map->map_read.read[i + 1] == '\n')
			error("Error, newline in map.", data);
		i++;
	}
}

int	map_init(t_data *data, t_map *map)
{
	if (check_extension(map->map_read.filename))
		error("Error, not .cub file", data);
	map->map_read.fd = open(map->map_read.filename, O_RDONLY);
	if (map->map_read.fd == -1)
		error("Error, unable to open map", data);
	map->map_read.read = NULL;
	map_read(data, map);
	if (close(map->map_read.fd) == -1)
		error("Error, unable to close map", data);
	map_nl_check(data, map);
	map->map = ft_split(map->map_read.read, '\n');
	if (!map->map)
		error("Error, split map malloc", data);
	map_meta(data, map);
	map_clear(data, map);
	map_fill(data, map);
	map_color(data, &map->color);
	return (0);
}
