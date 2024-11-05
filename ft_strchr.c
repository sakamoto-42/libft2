/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:27:51 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 21:16:46 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate character in string

// DESCRIPTION :
// The ft_strchr() function returns a pointer to the first occurrence
// of the character c in the string s

// Note : Here "character" means "byte"
// this function doesn't work with wide or multibyte characters

// RETURN VALUE :
// The ft_strchr() function return a pointer to the matched character
// or NULL if the character is not found
// The  terminating null byte is considered part of the string,
// so that if c is specified as '\0',
// this function return a pointer to the terminator
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
