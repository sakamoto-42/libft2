/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:20:53 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 11:28:10 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Paramètres :
// content : Le contenu du nouvel élément.

// Valeur de retour :
// Le nouvel élément

// Description :
// Alloue (avec malloc) et renvoie un nouvel élément.
// La variable membre ’content’ est
// initialisée à l’aide de la valeur du paramètre ’content’.
// La variable ’next’ est initialisée à NULL.
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
