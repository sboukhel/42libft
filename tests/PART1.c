/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PART1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 08:44:33 by sboukhel          #+#    #+#             */
/*   Updated: 2026/09/04 12:34:35 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define REPORT(name, test) printf("[%s] - %s\n", (test) ? "OK" : "KO", name)

static void	group_one(void)
{
	char	*input;

	input = "Hello World";
	REPORT("ft_isalpha", ft_isalpha('A') == 1
		&& ft_isalpha('5') == 0 && ft_isalpha('@') == 0);
	REPORT("ft_isalnum", ft_isalnum('A') == 1 && ft_isalnum('@') == 0);
	REPORT("ft_isdigit", ft_isdigit('5') == 1 && ft_isdigit('a') == 0);
	REPORT("ft_isascii", ft_isascii(65) == 1 && ft_isascii(200) == 0);
	REPORT("ft_isprint", ft_isprint('A') == 1 && ft_isprint('\n') == 0);
	REPORT("ft_strlen", ft_strlen("Hello") == 5 && ft_strlen("") == 0);
	REPORT("ft_strnstr", ft_strnstr(input, "World", 11) == input + 6
		&& ft_strnstr(input, "Foo", 11) == NULL);
	REPORT("ft_atoi", ft_atoi("42") == 42 && ft_atoi("   -42") == -42
		&& ft_atoi("abc") == 0);
}

static void	group_two(void)
{
	char	buffer[10];
	char	dst[10];
	size_t	result;

	ft_memset(buffer, 'A', 10);
	REPORT("ft_memset", memcmp(buffer, "AAAAAAAAAA", 10) == 0);
	ft_memset(buffer, 'X', 5);
	ft_bzero(buffer, 5);
	REPORT("ft_bzero", buffer[0] == 0 && buffer[1] == 0
		&& buffer[2] == 0 && buffer[3] == 0 && buffer[4] == 0);
	ft_strlcpy(buffer, "123456789", 10);
	ft_memmove(buffer + 2, buffer, 5);
	REPORT("ft_memmove", memcmp(buffer, "121234589", 9) == 0);
	result = ft_strlcpy(dst, "Hello", 10);
	REPORT("ft_strlcpy", result == 5 && memcmp(dst, "Hello", 6) == 0);
	ft_strlcpy(dst, "Foo", 10);
	result = ft_strlcat(dst, "Bar", 10);
	REPORT("ft_strlcat", result == 6 && memcmp(dst, "FooBar", 7) == 0);
	REPORT("ft_toupper", ft_toupper('a') == 'A' && ft_toupper('5') == '5');
}

static void	group_three(void)
{
	char	*input;
	char	*dup;
	void	*mem_result;

	input = "Hello World";
	REPORT("ft_tolower", ft_tolower('A') == 'a' && ft_tolower('5') == '5');
	REPORT("ft_strchr", ft_strchr(input, 'o') == input + 4
		&& ft_strchr(input, 'z') == NULL);
	REPORT("ft_strrchr", ft_strrchr(input, 'o') == input + 7
		&& ft_strrchr(input, 'z') == NULL);
	REPORT("ft_memcmp", ft_memcmp("abc", "abd", 3) < 0
		&& ft_memcmp("abc", "abc", 3) == 0);
	REPORT("ft_strncmp", ft_strncmp("Hello", "Help", 3) == 0
		&& ft_strncmp("Hello", "Help", 5) != 0);
	mem_result = ft_memchr(input, 'W', 11);
	REPORT("ft_memchr", mem_result == input + 6
		&& ft_memchr(input, 'z', 11) == NULL);
	dup = ft_strdup("Hello");
	REPORT("ft_strdup", dup != NULL && memcmp(dup, "Hello", 6) == 0);
	free(dup);
}

static void	group_four(void)
{
	char	dst_ft[30];
	char	dst_std[30];
	void	*ret_ft;
	void	*ret_std;

	ret_ft = ft_memcpy(dst_ft, "Hello, 42 Network!",
			sizeof("Hello, 42 Network!"));
	ret_std = memcpy(dst_std, "Hello, 42 Network!",
			sizeof("Hello, 42 Network!"));
	REPORT("ft_memcpy", ret_ft == dst_ft && ret_std == dst_std
		&& memcmp(dst_ft, dst_std, sizeof("Hello, 42 Network!")) == 0);
	ret_ft = ft_calloc(10, sizeof(int));
	ret_std = calloc(10, sizeof(int));
	REPORT("ft_calloc", ret_ft != NULL && ret_std != NULL
		&& memcmp(ret_ft, ret_std, 10 * sizeof(int)) == 0);
	free(ret_ft);
	free(ret_std);
}

int	main(void)
{
	printf("\n=== PART 1: LIBFT TESTS ===\n");
	group_one();
	group_two();
	group_three();
	group_four();
	printf("\n=== PART 1 COMPLETE ===\n");
	return (0);
}
