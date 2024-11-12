/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:27:36 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/12 10:30:49 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Paramètres :
// lst : L’adresse du pointeur vers un élément.
// f : L’adresse de la fonction à appliquer.

// Valeur de retour :
// Aucune

// Description :
// Itère sur la liste ’lst’
// et applique la fonction ’f’ au contenu chaque élément.
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
