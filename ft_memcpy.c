/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:29:38 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/06 09:08:51 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy memory area

// DESCRIPTION :
// The ft_memcpy() function copies n bytes from memory area src
// to memory area dest
// /!\ IMPORTANT :
// The memory areas must not overlap
// Use ft_memmove if the memory areas do overlap

// RETURN VALUE :
// The ft_memcpy() function returns a pointer to dest
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *) dest;
	src_ptr = (const unsigned char *) src;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return ((void *)dest);
}
