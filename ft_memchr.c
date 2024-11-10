/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:07:41 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 15:39:02 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// scan memory for a character

// DESCRIPTION :
// The ft_memchr() function scans the initial n bytes of the memory area
// pointed to by s for the first instance of c
// Both c and the bytes of
// the memory area pointed to by s are interpreted as unsigned char

// RETURN VALUE :
// The ft_memchr() function return a pointer to the matching
// byte or NULL if the character does not occur in the given memory area
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;
	size_t				i;

	s_ptr = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char) s_ptr[i] == (unsigned char) c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
