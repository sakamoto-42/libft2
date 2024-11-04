/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:32:18 by julien            #+#    #+#             */
/*   Updated: 2024/11/04 22:00:22 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copy memory area

// DESCRIPTION :
// The ft_memmove() function copies n bytes from memory area src
// to memory area dest.
// The memory areas may overlap: copying takes place as though
// the bytes in src are first copied into a temporary array that does not
// overlap src or dest, and the bytes are then copied from the temporary
// array to dest

// RETURN VALUE
// The ft_memmove() function returns a pointer to dest
void	*memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_start_ptr;
	unsigned char		*dest_end_ptr;
	const unsigned char	*src_start_ptr;
	const unsigned char	*src_end_ptr;

	/*
	if (!dest || !src)
		return (NULL);
	*/

	dest_start_ptr = (unsigned char *) dest;
	dest_end_ptr = ((unsigned char *) dest) + n - 1;
	src_start_ptr = (unsigned char *) src;
	src_end_ptr = ((unsigned char *) src) + n - 1;
	if (src_start_ptr > dest_start_ptr)
	{
		while (n--)
			*dest_start_ptr++ = *src_start_ptr++;
	}
	else
	{
		while (n--)
			*dest_end_ptr-- = *src_end_ptr--;
	}
}
