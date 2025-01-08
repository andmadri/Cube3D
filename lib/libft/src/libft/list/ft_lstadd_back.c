/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:28:10 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 17:51:03 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_lstadd_back(t_libft **lst, t_libft *lstnew)
{
	t_libft	*tmp;

	tmp = ft_lstlast(*lst);
	if (!tmp)
		*lst = lstnew;
	else
		tmp->next = lstnew;
}
