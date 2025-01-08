/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: veno <veno@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 21:46:50 by veno          #+#    #+#                 */
/*   Updated: 2024/05/26 14:44:42 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static	int	parse_mandatory(const char **format, va_list *args,
						unsigned int *count, t_flags *flags)
{
	if ((**format) == (const char) 'c')
		printf_c(va_arg(*args, int), count);
	else if (**format == 's')
		printf_s(va_arg(*args, char *), count);
	else if (**format == '%')
		printf_c('%', count);
	else if (**format == 'p')
		printf_p(va_arg(*args, unsigned long), count);
	else if (**format == 'd' || **format == 'i')
		printf_int(va_arg(*args, int), count, *flags);
	else if (**format == 'u')
		printf_u(va_arg(*args, unsigned int), count);
	else if (**format == 'x')
		printf_x(va_arg(*args, unsigned int), count, *flags);
	else if (**format == 'X')
		printf_x_upper(va_arg(*args, unsigned int), count, *flags);
	(*format)++;
	return (0);
}

static	int	parse_bonus(const char **format, va_list *args, unsigned int *count,
					t_flags *flags)
{
	(void) args;
	(void) count;
	while (**format != '\0' && ft_strchr("# +", (**format)))
	{
		if (**format == '#')
			flags->hash = 1;
		else if (**format == ' ')
			flags->space = 1;
		else if (**format == '+')
			flags->plus = 1;
		else if (ft_strchr("cspdiuxX%%", **format))
			break ;
		(*format)++;
	}
	return (0);
}

static	t_flags	flags_inti(void)
{
	t_flags	flags;

	flags.spec = 0;
	flags.width = 0;
	flags.star = 0;
	flags.zero = 0;
	flags.minus = 0;
	flags.dot = 0;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

static	int	parse_format(const char *format, va_list *args, unsigned int *count)
{
	t_flags	flags;

	while (*format)
	{
		if (*format == '%')
		{
			if (*(++format) == '\0')
				return (-1);
			flags = flags_inti();
			if (*format != '\0' && ft_strchr("# +", *format))
				parse_bonus(&format, args, count, &flags);
			if (*format != '\0' && ft_strchr("cspdiuxX%%", *format))
				parse_mandatory(&format, args, count, &flags);
			else
			{
				format--;
				printf_c(*(format++), count);
				printf_c(*(format++), count);
			}
		}
		else
			printf_c(*(format++), count);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	unsigned int	count;
	va_list			args;

	if (!format || *format == '\0')
		return (0);
	count = 0;
	va_start(args, format);
	if (parse_format(format, &args, &count) == -1)
		return (-1);
	va_end(args);
	return (count);
}
