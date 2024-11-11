/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:22:19 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/10 17:00:56 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// lst : L’adresse du pointeur vers le premier élément de la liste.
// new : L’adresse de l’élément à rajouter à la liste.

// Valeur de retour :
// Aucune

// Description :
// Ajoute l’élément ’new’ au début de la liste.
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
