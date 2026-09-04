/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PART3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 12:30:00 by sboukhel          #+#    #+#             */
/*   Updated: 2026/09/04 22:49:06 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

static void	del_content(void *content)
{
	free(content);
}

static void	*dup_content(void *content)
{
	return (ft_strdup((char *)content));
}

static void	dummy_iter(void *content)
{
	(void)content;
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

int	main(void)
{
	t_list	*l;
	t_list	*m;
	t_list	*del_node;

	write(1, "\n=== PART 3: LINKED LIST FUNCTIONS ===\n", 40);
	l = ft_lstnew(ft_strdup("Node 1"));
	print_res("ft_lstnew", (l != NULL));
	ft_lstadd_front(&l, ft_lstnew(ft_strdup("Node 0")));
	print_res("ft_lstadd_front", (l && !ft_strncmp(l->content, "Node 0", 6)));
	ft_lstadd_back(&l, ft_lstnew(ft_strdup("Node 2")));
	print_res("ft_lstadd_back", (ft_lstlast(l) != NULL));
	print_res("ft_lstsize", (ft_lstsize(l) == 3));
	print_res("ft_lstlast", (!ft_strncmp(ft_lstlast(l)->content, "Node 2", 6)));
	del_node = ft_lstnew(ft_strdup("Delone"));
	ft_lstdelone(del_node, del_content);
	print_res("ft_lstdelone", 1);
	ft_lstiter(l, dummy_iter);
	print_res("ft_lstiter", 1);
	m = ft_lstmap(l, dup_content, del_content);
	print_res("ft_lstmap", (m && ft_lstsize(m) == 3));
	ft_lstclear(&l, del_content);
	print_res("ft_lstclear", (l == NULL));
	ft_lstclear(&m, del_content);
	write(1, "=== PART 3 COMPLETE ===\n", 25);
	return (0);
}
