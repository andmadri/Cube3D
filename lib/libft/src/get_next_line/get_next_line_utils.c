/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/14 22:16:29 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 18:02:16 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//	gnl_free_master - combined free function, used for most cases when
//	my malloc mem has to be free'd

int	gnl_free_master(t_gnl **list, t_gnl **clean_node, char **buf, char **nl)
{
	t_gnl	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->buffer);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_node && (*clean_node)->buffer[0] != '\0')
		*list = *clean_node;
	else if (buf || clean_node || nl)
	{
		if (buf)
			free(*buf);
		if (clean_node)
			free(*clean_node);
		if (nl)
		{
			free(*nl);
			*nl = NULL;
		}
	}
	return (-1);
}

//	gnl_lst_to_next_line - reading and copying lst until new line char

void	gnl_lst_to_next_line(t_gnl *lst, char *next_line)
{
	int	i;
	int	j;

	if (!lst)
		return ;
	i = 0;
	while (lst)
	{
		j = 0;
		while (lst->buffer[j])
		{
			if (lst->buffer[j] == '\n')
			{
				next_line[i++] = '\n';
				next_line[i] = '\0';
				return ;
			}
			next_line[i++] = lst->buffer[j++];
		}
		lst = lst->next;
	}
}

//	gnl_ft_calloc - pretty much calloc from libft
//	included b_zero in-line to not have another func

void	*gnl_ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		n;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	else if (!(((nmemb * size) / size) == nmemb))
		return (NULL);
	ptr = ft_calloc(nmemb, size);
	if (!ptr)
		return (NULL);
	n = nmemb * size;
	while (n--)
		((unsigned char *)ptr)[n] = '\0';
	return (ptr);
}

//	gnl_lst_until_nl1 - counting characters until new line
//	returning 0 if no nl is found (use for the if statement)

int	gnl_lst_until_nl1(t_gnl *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst->buffer[i])
	{
		if (lst->buffer[i] == '\n')
			return (1);
		i++;
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	i = 0;
	while (lst->buffer[i])
	{
		if (lst->buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//	gnl_lst_until_nl - pretty much copy of gnl_lst_until_nl -
//	characters until
//	new line, returning number of characters until nl or end of list

int	gnl_lst_until_nl(t_gnl *lst)
{
	int	i;
	int	ret;

	ret = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->buffer[i])
		{
			if (lst->buffer[i] == '\n')
				return (++ret);
			i++;
			ret++;
		}
		lst = lst->next;
	}
	return (ret);
}
