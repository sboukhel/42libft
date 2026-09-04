/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PART2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:30:00 by sboukhel          #+#    #+#             */
/*   Updated: 2026/09/04 15:09:33 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

static char	mapi_f(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static void	iteri_f(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	print_res(const char *name, int passed)
{
	if (passed)
		write(1, "[OK] - ", 7);
	else
		write(1, "[KO] - ", 7);
	write(1, name, ft_strlen(name));
	write(1, "\n", 1);
}

static void	test_part2_b(void)
{
	char	*r;
	char	str[5];

	r = ft_strmapi("hello", mapi_f);
	print_res("ft_strmapi", (r && !ft_strncmp(r, "HELLO", 5)));
	free(r);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = '\0';
	ft_striteri(str, iteri_f);
	print_res("ft_striteri", !ft_strncmp(str, "AB", 2));
	write(1, "\nOutput tests:\n", 15);
	ft_putchar_fd('X', 1);
	write(1, "\n", 1);
	ft_putstr_fd("Hello\n", 1);
	ft_putendl_fd("World", 1);
	ft_putnbr_fd(-42042, 1);
	write(1, "\n", 1);
	print_res("fd functions (4)", 1);
}

int	main(void)
{
	char	*r;
	char	**tab;

	write(1, "\n=== PART 2: ALL 11 FUNCTIONS ===\n", 35);
	r = ft_substr("Hello World", 6, 5);
	print_res("ft_substr", (r && !ft_strncmp(r, "World", 5)));
	free(r);
	r = ft_strjoin("Hello ", "42");
	print_res("ft_strjoin", (r && !ft_strncmp(r, "Hello 42", 8)));
	free(r);
	r = ft_strtrim("  Hello  ", " ");
	print_res("ft_strtrim", (r && !ft_strncmp(r, "Hello", 5)));
	free(r);
	tab = ft_split("a,b,,c", ',');
	print_res("ft_split", (tab && tab[0] && tab[1] && tab[2] && !tab[3]));
	r = ft_itoa(-2147483648);
	print_res("ft_itoa", (r && !ft_strncmp(r, "-2147483648", 11)));
	free(r);
	test_part2_b();
	write(1, "\n=== PART 2 COMPLETE ===\n", 25);
	return (0);
}
