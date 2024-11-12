/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:26:45 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/12 09:22:00 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Paramètres :
// lst : L’adresse du pointeur vers un élément.
// del : L’adresse de la fonction permettant de
// supprimer le contenu d’un élément.

// Valeur de retour :
// Aucune

// Description :
// Supprime et libère la mémoire de l’élément passé en
// paramètre, et de tous les éléments qui suivent, 
// à l’aide de ’del’ et de free
// Enfin, le pointeur initial doit être mis à NULL.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
