/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:13:39 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 18:03:23 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_libft	*ft_lstnew(void *content)
{
	t_libft	*ret;

	ret = ft_calloc(1, sizeof(t_libft));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
