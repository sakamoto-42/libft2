/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:26:02 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 06:43:51 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size-bounded string copying and concatenation

// DESCRIPTION :
// The ft_strlcat() function concatenate two strings
// This is designed to be safer, more consistent, and
// less error prone replacements for ft_strncat()
// Unlike this function, ft_strlcat() take the full size of the
// buffer (not just the length) and guarantee to NUL-terminate the result
// (as long as there is at least one byte free in dst)
// Note that a byte for the NUL should be included in size
// Also note that ft_strlcat() only operate on true “C” strings
// This means that both src and dst must be NUL-terminated

// The ft_strlcat() function appends the NUL-terminated string src
// to the end of dst
// It will append at most size - strlen(dst) - 1 bytes,
// NUL-terminating the result

// RETURN VALUES :
// The ft_strlcat() function return the total length of the string
// they tried to create
// That means the initial length of dst plus the length of src
// While this may seem somewhat confusing,
// it was done to make truncation detection simple

// Note, however, that if ft_strlcat() traverses size characters
// without finding a NUL,
// the length of the string is considered to be size
// and the destination string will not be NUL-terminated
// (since there was no space for the NUL)
// This keeps ft_strlcat() from running off the end of a string
// In practice this should not happen
// (as it means that either size is incorrect
// or that dst is not a proper “C” string)
// The check exists to prevent potential security problems in incorrect code
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len == size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
