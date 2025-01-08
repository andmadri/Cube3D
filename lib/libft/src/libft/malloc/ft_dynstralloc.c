/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dynstralloc.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/04 18:06:08 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 18:16:44 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_dynstralloc(char *original_str, int *capacity)
{
	char	*new_str;

	*capacity *= 2;
	new_str = ft_calloc(*capacity + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	if (original_str)
	{
		ft_strlcpy(new_str, original_str, ft_strlen(original_str) + 1);
		free(original_str);
	}
	return (new_str);
}
