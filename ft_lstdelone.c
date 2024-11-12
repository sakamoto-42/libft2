/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:25:35 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/12 08:38:40 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Paramètres :
// lst : L’élément à free
// del : L’adresse de la fonction permettant de
// supprimer le contenu de l’élément.

// Valeur de retour :
// Aucune

// Description :
// Libère la mémoire de l’élément passé en argument
// en utilisant la fonction ’del’ puis avec free.
// La mémoire de ’next’ ne doit pas être free.
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
