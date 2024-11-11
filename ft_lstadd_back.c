/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:24:53 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 12:12:23 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// lst : L’adresse du pointeur vers le premier élément de la liste.
// new : L’adresse du pointeur vers l’élément à rajouter à la liste.

// Valeur de retour :
// Aucune

// Description :
// Ajoute l’élément ’new’ à la fin de la liste.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}