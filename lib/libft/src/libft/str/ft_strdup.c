/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 14:11:08 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 17:20:07 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s, ft_strlen(s) + 1);
		return (str);
	}
	return (str);
}
