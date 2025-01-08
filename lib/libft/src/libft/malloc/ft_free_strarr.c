/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_free_strarr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 17:50:52 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 18:16:46 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_free_strarr(char **strarr)
{
	int	i;

	i = 0;
	if (!strarr)
		return ;
	while (strarr[i])
	{
		free(strarr[i]);
		strarr[i] = NULL;
		i++;
	}
	free(strarr);
	strarr = NULL;
}
