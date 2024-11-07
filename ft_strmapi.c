/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:05:42 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 09:07:08 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Paramètres :
// s: La chaîne de caractères sur laquelle itérer.
// f: La fonction à appliquer à chaque caractère.

// Valeur de retour :
// La chaîne de caractères résultant des applications successives de ’f’.
// Retourne NULL si l’allocation échoue.

// Description :
// Applique la fonction ’f’ à chaque caractère de
// la chaîne de caractères ’s’, passant son index
// comme premier argument et le caractère lui-même
// comme second argument. Une nouvelle chaîne de
// caractères est créée (avec malloc(3)), résultant
// des applications successives de ’f’.
char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	
}