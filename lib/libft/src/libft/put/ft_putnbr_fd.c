/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 12:28:07 by crasche       #+#    #+#                 */
/*   Updated: 2024/05/26 14:43:06 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;

	if (n < 0)
	{
		digit = ((n % 10) * -1) + 48;
		n /= 10;
		n *= -1;
		write(fd, "-", 1);
	}
	else
	{
		digit = (n % 10) + 48;
		n /= 10;
	}
	if (n > 0)
		ft_putnbr_fd(n, fd);
	write(fd, &digit, 1);
}
