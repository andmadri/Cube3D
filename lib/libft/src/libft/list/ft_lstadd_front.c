/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 14:18:11 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 17:50:49 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_lstadd_front(t_libft **lst, t_libft *lstnew)
{
	lstnew->next = *lst;
	*lst = lstnew;
}
