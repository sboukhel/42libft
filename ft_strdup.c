/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 10:03:11 by sboukhel          #+#    #+#             */
/*   Updated: 2026/08/20 10:16:52 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_rdup(const char *s)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	*str = malloc(len * sizeof(char) + 1);
	len = 0;
	while (s[len])
	{
		str[len] = s[len];
		len++;
	}
	str[len] = '\0';
	return (0);
}
