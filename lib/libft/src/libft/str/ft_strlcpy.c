/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/05 12:30:25 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 23:23:00 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned char		*d;
	unsigned const char	*s;
	int					src_len;

	d = (unsigned char *) dst;
	s = (unsigned const char *) src;
	src_len = 0;
	if (src)
		src_len = ft_strlen(src);
	if (size <= 0)
		return (src_len);
	else if (src_len == 0)
	{
		*d = '\0';
		return (src_len);
	}
	while (--size && *s != '\0')
		*d++ = *s++;
	*d = '\0';
	return (src_len);
}
