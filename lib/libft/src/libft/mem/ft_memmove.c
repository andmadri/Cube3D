/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:35:48 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 14:43:06 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	unsigned char		*d_last;
	unsigned const char	*s_last;

	d = (unsigned char *) dest;
	s = (unsigned const char *) src;
	if (!dest && !src)
		return (dest);
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d_last = d + (n - 1);
		s_last = s + (n - 1);
		while (n--)
			*d_last-- = *s_last--;
	}
	return (dest);
}
