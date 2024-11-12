/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:29:18 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 09:24:25 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate character in string

// DESCRIPTION :
// The ft_strrchr() function returns a pointer to the last occurrence
// of the character c in the string s

// Note : Here "character" means "byte"
// This function do not work with wide or multibyte characters.

// RETURN VALUE :
// The ft_strrchr() function return a pointer to the matched character
// or NULL if the character is not found
// The terminating null byte is considered part of the string,
// so that if c is specified as '\0',
// this function return a pointer to the terminator.
char	*ft_strrchr(const char *s, int c)
{
	const char	*s_start;

	s_start = s;
	while (*s)
		s++;
	if ((unsigned char) c == '\0')
		return ((char *)s);
	while (s >= s_start)
	{
		s--;
		if (*s == (unsigned char) c)
			return ((char *)s);
	}
	return (NULL);
}
