/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 22:16:05 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 14:45:07 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	clean_for_next_call - cleaning lst for the next call and freeing
//	all characters we already used in the current string

static int	clean_for_next_call(t_gnl **lst, char **next_line)
{
	t_gnl	*last_node;
	t_gnl	*clean_node;
	int		i;
	int		k;
	char	*clean_buffer;

	clean_buffer = gnl_ft_calloc(BUFFER_SIZE + 1, 1);
	if (!clean_buffer)
		return (gnl_free_master(lst, 0, 0, next_line));
	clean_node = gnl_ft_calloc(sizeof(t_gnl), 1);
	if (!clean_node)
		return (gnl_free_master(lst, 0, &clean_buffer, next_line));
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	i = 0;
	k = 0;
	while (last_node->buffer[i] && last_node->buffer[i] != '\n')
		i++;
	while (last_node->buffer[i] && last_node->buffer[++i])
		clean_buffer[k++] = last_node->buffer[i];
	clean_node->buffer = clean_buffer;
	clean_node->next = NULL;
	gnl_free_master(lst, &clean_node, &clean_buffer, 0);
	return (0);
}

//	lst_to_line - reading lst and creating "next_line" string
//	calloc it's size and returning the string to get_next_line

static char	*lst_to_line(t_gnl *lst)
{
	int		nl_len;
	char	*next_line;

	if (!lst)
		return (NULL);
	nl_len = gnl_lst_until_nl(lst);
	next_line = gnl_ft_calloc(nl_len + 1, 1);
	if (!next_line)
		return (NULL);
	gnl_lst_to_next_line(lst, next_line);
	return (next_line);
}

//	add_lst_node - taking malloced read characters and adding
//	them as list node to lst

static int	add_lst_node(t_gnl **lst, char *buffer)
{
	t_gnl	*new;

	new = gnl_ft_calloc(sizeof(t_gnl), 1);
	if (!new)
	{
		free(buffer);
		buffer = NULL;
		return (-1);
	}
	new->buffer = buffer;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
	{
		while ((*lst)->next != NULL)
			lst = &(*lst)->next;
		(*lst)->next = new;
	}
	return (0);
}

//	read_to_list - calloc BUFFER_SIZE string and reading
//	BUFFER_SIZE chars, calling add_lst_node to add a node

static int	read_to_list(t_gnl **lst, int fd)
{
	char	*buffer;
	int		read_ret;

	while (!(gnl_lst_until_nl1(*lst)))
	{
		buffer = gnl_ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (-1);
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == 0)
		{
			free(buffer);
			buffer = NULL;
			return (0);
		}
		if (add_lst_node(lst, buffer) == -1)
			return (gnl_free_master(lst, 0, 0, 0));
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_gnl	*lst[4096];
	char			*next_line;

	if (fd < 0 || fd > 4095 || read(fd, &next_line, 0) < 0 || BUFFER_SIZE <= 0)
	{
		gnl_free_master(&lst[fd], 0, 0, 0);
		return (NULL);
	}
	if (read_to_list(&lst[fd], fd) == -1 || !lst[fd])
	{
		gnl_free_master(&lst[fd], 0, 0, 0);
		return (NULL);
	}
	next_line = lst_to_line(lst[fd]);
	if (next_line == NULL)
		gnl_free_master(&lst[fd], 0, 0, 0);
	else
		clean_for_next_call(&lst[fd], &next_line);
	return (next_line);
}
