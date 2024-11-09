/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:29:53 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 10:48:47 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Paramètres :
// lst : L’adresse du pointeur vers un élément.
// f : L’adresse de la fonction à appliquer.
// del : L’adresse de la fonction permettant de
// supprimer le contenu d’un élément.

// Valeur de retour :
// La nouvelle liste.
// NULL si l’allocation échoue

// Description :
// Itère sur la liste ’lst’ et applique la fonction
// ’f’ au contenu de chaque élément.
// Crée une nouvelle liste résultant des applications successives de ’f’.
// La fonction ’del’ est là pour détruire le contenu d’un élément si nécessaire.
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{

}
