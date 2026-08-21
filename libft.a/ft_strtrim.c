/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 21:52:27 by sboukhel          #+#    #+#             */
/*   Updated: 2026/08/21 10:59:17 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	find_set(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		last;
	int		total;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	last = ft_strlen(s1) - 1;
	while (s1[start] && find_set(s1[start], set))
		start++;
	while (start <= last && s1[last] && find_set(s1[last], set))
		last--;
	total = last - start;
	str = (char *)malloc((total + 2) * sizeof(char));
	if (!str)
		return (NULL);
	total = 0;
	while (start <= last)
	{
		str[total++] = s1[start++];
	}
	str[total] = '\0';
	return (str);
}
