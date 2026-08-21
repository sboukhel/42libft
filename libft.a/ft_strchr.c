/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 09:43:31 by sboukhel          #+#    #+#             */
/*   Updated: 2026/08/20 09:43:49 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	char_c;

	char_c = (char)c;
	while (*s != '\0')
	{
		if (*s == char_c)
			return ((char *)s);
		s++;
	}
	if (*s == char_c)
		return ((char *)s);
	return (NULL);
}
