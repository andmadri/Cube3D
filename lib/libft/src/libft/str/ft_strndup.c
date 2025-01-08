/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 14:11:08 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/27 18:23:12 by veno          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;

	str = ft_calloc(n + 1, sizeof(char));
	if (str)
	{
		ft_strlcpy(str, s, n + 1);
		return (str);
	}
	return (str);
}
