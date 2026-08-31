/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 10:59:28 by sboukhel          #+#    #+#             */
/*   Updated: 2026/08/27 12:09:07 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n <= -10 || n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_putnbr(int nb, char *str)
{
	long	n;
	int		i;

	n = nb;
	i = intlen(nb);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	if (n == 0)
		str[i] = '0';
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_putnbr(n, str);
	return (str);
}
