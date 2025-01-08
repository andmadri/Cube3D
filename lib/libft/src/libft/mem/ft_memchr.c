/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 12:32:36 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 14:43:06 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*scr;
	unsigned char	chr;

	scr = (unsigned char *) s;
	chr = (unsigned char) c;
	while (n--)
	{
		if (*scr == chr)
			return (scr);
		scr++;
	}
	return (NULL);
}
