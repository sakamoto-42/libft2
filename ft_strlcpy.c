/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:23:29 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 06:56:08 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size-bounded string copying

// DESCRIPTION :
// The ft_strlcpy() function copy a string
// This is designed to be safer, more consistent, and less error prone
// replacements for strncpy
// Unlike this function, ft_strlcpy() take the full size of the
// buffer (not just the length) and guarantee to NUL-terminate the result
// (as long as size is larger than 0)
// Note that a byte for the NUL should be included in size
// Also note that ft_strlcpy() only operate on true “C” strings
// This means that src must be NUL-terminated

// The ft_strlcpy() function copies up to size - 1 characters
// from the NUL-terminated string src to dst, NUL-terminating the result

// RETURN VALUES :
// The ft_strlcpy() function return the total length
// of the string they tried to create
// That means the length of src
// While this may seem somewhat confusing,
// it was done to make truncation detection simple.
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
