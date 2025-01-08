/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 12:20:20 by crasche       #+#    #+#                 */
/*   Updated: 2024/06/04 18:03:06 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include <stdlib.h>
#include <stdio.h>

static	int	strcounter(char const *s, char c)
{
	int	counter;

	if (*s == c)
		counter = 0;
	else
		counter = 1;
	s++;
	while (*s)
	{
		if (*s == c)
			s++;
		else if (*(s - 1) != c)
			s++;
		else
		{
			s++;
			counter++;
		}
	}
	return (counter);
}

static	int	freeall(char **array, int curr_str)
{
	while (--curr_str >= 0)
		free(array[curr_str]);
	free(array);
	return (0);
}

static	int	splitting(const char *s, const char c, char **array, int str_count)
{
	int	curr_str;
	int	str_curr_len;

	curr_str = 0;
	while (curr_str < str_count)
	{
		str_curr_len = 0;
		while (*s == c)
			s++;
		while (*(s + str_curr_len) != c && *(s + str_curr_len))
			str_curr_len++;
		array[curr_str] = ft_calloc(sizeof(char), (str_curr_len + 1));
		if (!array[curr_str])
			return (freeall(array, curr_str));
		if (!ft_strlen(s))
			array[0][0] = '\0';
		else
			ft_strlcpy(array[curr_str], s, str_curr_len + 1);
		s = s + str_curr_len;
		curr_str++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		str_count;

	if (!ft_strlen(s))
		str_count = 0;
	else
		str_count = strcounter(s, c);
	array = ft_calloc(sizeof(char *), (str_count + 1));
	if (!array)
		return (NULL);
	array[str_count] = NULL;
	if (splitting(s, c, array, str_count) == 0)
		return (NULL);
	return (array);
}
