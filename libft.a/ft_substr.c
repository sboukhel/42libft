/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 13:47:52 by sboukhel          #+#    #+#             */
/*   Updated: 2026/09/03 19:40:15 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		sub_len;
	unsigned int		s_len;
	char				*str;

	s_len = ft_strlen(s);
	if (s_len <= start)
		sub_len = 0;
	else if (len > s_len - start)
		sub_len = s_len - start;
	else
		sub_len = len;
	str = malloc(sub_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
