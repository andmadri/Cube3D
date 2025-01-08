/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:50:07 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 14:43:06 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_libft	*ft_lstmap(t_libft *lst, void *(*f)(void *), void (*del)(void *))
{
	t_libft	*ret;
	t_libft	*buffer;

	ret = 0;
	while (lst)
	{
		buffer = ft_lstnew(f(lst->content));
		if (!buffer)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, buffer);
		lst = lst->next;
	}
	return (ret);
}
