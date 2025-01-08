/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 11:52:24 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 18:04:18 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static	int	isset(const char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len;

	len = ft_strlen(s1);
	while (isset(*s1, set))
	{
		s1++;
		len--;
	}
	while (isset(*(s1 + len - 1), set))
		len--;
	if (len <= 0)
		len = 0;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
