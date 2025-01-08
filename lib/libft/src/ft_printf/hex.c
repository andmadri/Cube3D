/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: veno <veno@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 17:39:55 by veno          #+#    #+#                 */
/*   Updated: 2024/05/26 14:44:35 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	printf_get_hex(unsigned long n, char *number)
{
	unsigned long	num;
	unsigned int	len;
	char			*hex;

	hex = "0123456789abcdef";
	len = 0;
	num = n;
	while (n != 0 && ++len)
		n /= 16;
	while (num > 0)
	{
		number[--len] = hex[(num % 16)];
		num /= 16;
	}
}

void	printf_p(unsigned long n, unsigned int *count)
{
	char	number[23];

	ft_bzero(number, 23);
	ft_strlcpy(number, "0x", 3);
	if (n == 0)
		ft_strlcpy(number, "(nil)", 6);
	else
		printf_get_hex(n, &number[2]);
	printf_s(number, count);
}

void	printf_x(unsigned int n, unsigned int *count, t_flags flags)
{
	char	number[23];

	ft_bzero(number, 23);
	if (n == 0)
		number[0] = '0';
	else if (flags.hash == 1)
	{
		ft_strlcpy(number, "0x", 3);
		printf_get_hex(n, &number[2]);
	}
	else
		printf_get_hex(n, &number[0]);
	printf_s(number, count);
}

void	printf_x_upper(unsigned int n, unsigned int *count, t_flags flags)
{
	char	number[23];
	int		i;

	ft_bzero(number, 23);
	if (n == 0)
		number[0] = '0';
	else if (flags.hash == 1)
	{
		ft_strlcpy(number, "0x", 3);
		printf_get_hex(n, &number[2]);
	}
	else
		printf_get_hex(n, &number[0]);
	i = -1;
	while (number[++i])
		number[i] = (char)ft_toupper((char)number[i]);
	printf_s(number, count);
}
