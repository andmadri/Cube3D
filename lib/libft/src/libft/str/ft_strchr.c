/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 14:26:40 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 14:43:06 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	if ((unsigned char) *s == (unsigned char) c)
		return ((char *) s);
	while (*s++ != '\0')
		if ((unsigned char) *s == (unsigned char) c)
			return ((char *) s);
	return (NULL);
}
