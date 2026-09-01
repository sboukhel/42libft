/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboukhel <sboukhel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 15:53:42 by sboukhel          #+#    #+#             */
/*   Updated: 2026/09/01 21:09:46 by sboukhel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*createnode;

	createnode = (t_list *)malloc(sizeof(t_list));
	if (!createnode)
		return (NULL);
	createnode->content = content;
	createnode->next = NULL;
	return (createnode);
}
