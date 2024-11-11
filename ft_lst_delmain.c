/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delmain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:25:35 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/11 19:19:26 by sakamoto-42      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	ft_lstdelelement(void *content)
{
	if (content)
	content = NULL;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	lst->content = NULL;
	free(lst);
}

t_list	*ft_lstnewelem(void *content)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(*lst));
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_getlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddlast(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_getlast(*lst);
	last->next = new;
}

void	ft_relink(t_list **lst, t_list *todel)
{
	t_list	*current;

	if (!lst || !(*lst) || !todel)
		return ;
	current = *lst;
	if (current == todel)
	{
		current = current->next;
		return ;
	}
	while (current->next && current->next != todel)
		current = current->next;
	if (current->next && current->next == todel)
		current->next = todel->next;
}

int	main(void)
{
	t_list 	*head;
	t_list	*to_del;

	head = ft_lstnewelem(strdup("Coucou "));
	to_del = ft_lstnewelem(strdup("tout "));
	ft_lstaddlast(&head, to_del);
	ft_lstaddlast(&head, ft_lstnewelem(strdup("le ")));
	ft_lstaddlast(&head, ft_lstnewelem(strdup("monde !")));
	ft_relink(&head, to_del);
	ft_lstdelone(to_del, ft_lstdelelement);
	while (head)
	{
		printf("%s", (char *)head->content);
		head = head->next;
	}
}
