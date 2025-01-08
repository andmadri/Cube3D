/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 14:26:27 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 17:21:03 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include <stdio.h>

static	void	getstring(int n, char *buffer, int *buffer_len)
{
	int	i;
	int	pre;

	i = 0;
	pre = 1;
	if (n < 0)
	{
		buffer[i] = ((n % 10) * -1) + 48;
		n = n / 10;
		n *= -1;
		pre *= -1;
		i++;
	}
	while (n != 0)
	{
		buffer[i] = (n % 10) + 48;
		buffer[i + 1] = '\0';
		n = n / 10;
		i++;
	}
	if (pre == -1)
		buffer[i] = '-';
	*buffer_len = (int) ft_strlen(buffer);
}

char	*ft_itoa(int n)
{
	char	buffer[20];
	char	*str;
	int		buffer_len;
	int		i;

	ft_bzero(buffer, 20);
	if (n == 0)
	{
		buffer_len = 1;
		buffer[0] = '0';
	}
	else
		getstring(n, buffer, &buffer_len);
	str = ft_calloc(sizeof(char), (buffer_len + 1));
	if (!str)
		return (NULL);
	str[buffer_len--] = '\0';
	i = 0;
	while (buffer_len >= 0)
	{
		str[i] = buffer[buffer_len];
		i++;
		buffer_len--;
	}
	return (str);
}
