/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:29:18 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/06 15:38:41 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

// locate character in string

// DESCRIPTION :
// The ft_strrchr() function returns a pointer to the last occurrence
// of the character c in the string s

// Note : Here "character" means "byte"
// This function do not work with wide or multibyte characters

// RETURN VALUE :
// The ft_strrchr() function return a pointer to the matched character
// or NULL if the character is not found
// The terminating null byte is considered part of the string,
// so that if c is specified as '\0',
// this function return a pointer to the terminator
char	*ft_strrchr(const char *s, int c)
{
	const char	*s_start;

	s_start = s;
	while (*s)
		s++;
	if (c == '\0')
		return ((char *)s);
	while (s >= s_start)
	{
		s--;
		if (*s == c)
			return ((char *)s);
	}
	return (NULL);
}