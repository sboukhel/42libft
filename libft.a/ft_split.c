/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 11:09:56 by sboukhel          #+#    #+#             */
/*   Updated: 2026/08/27 10:39:21 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_split(char **result)
{
	int	i;

	i = 0;
	if (!result)
		return ;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

int	count_world(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

char	**full_world(char **result, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		result[j] = malloc(sizeof(char) * (i - start + 1));
		if (!result[j])
		{
			free_spilt(result);
			return (NULL);
		}
		ft_strlcpy(result[j], s + start, i - start + 1);
		j++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			world;
	const char	*str;

	world = count_world(s, c);
	result = (char **)malloc(sizeof(char) * (world + 1));
	if (!result)
		return (NULL);
	str = (const char *)s;
	if (!full_world(result, str, c))
		return (NULL);
	return (result);
}
