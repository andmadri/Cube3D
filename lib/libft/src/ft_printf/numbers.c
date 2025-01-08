/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   numbers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: veno <veno@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/03 17:40:03 by veno          #+#    #+#                 */
/*   Updated: 2024/05/26 14:44:39 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	printf_int(int n, unsigned int *count, t_flags flags)
{
	int		num;
	int		len;

	if (n == 0 && flags.plus == 1)
		return ((void)printf_s("+0", count));
	else if (n == 0 && flags.plus == 0 && flags.space == 1)
		return ((void)printf_s(" 0", count));
	else if (n == 0)
		return ((void)printf_s("0", count));
	len = 0;
	num = n;
	while (num != 0 && ++len)
		num /= 10;
	printf_int_digits(n, count, len, flags);
}

void	printf_int_digits(int n, unsigned int *count, int len, t_flags flags)
{
	char	number[12];

	ft_bzero(number, 12);
	if (n < 0)
	{
		number[0] = '-';
		number[len] = ((n % 10) * -1) + '0';
		n /= -10;
	}
	else if (flags.plus == 1)
	{
		number[0] = '+';
		len++;
	}
	else if (flags.plus == 0 && flags.space == 1)
	{
		number[0] = ' ';
		len++;
	}
	while (n > 0)
	{
		number[--len] = (n % 10) + '0';
		n /= 10;
	}
	printf_s(number, count);
}

void	printf_u(unsigned int n, unsigned int *count)
{
	unsigned int	num;
	int				len;
	char			number[11];

	if (n == 0)
		return ((void)printf_s("0", count));
	ft_bzero(number, 11);
	len = 0;
	num = n;
	while (num != 0 && ++len)
		num /= 10;
	while (n > 0)
	{
		number[--len] = (n % 10) + '0';
		n /= 10;
	}
	printf_s(number, count);
}
