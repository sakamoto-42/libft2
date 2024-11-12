/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:43:26 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 11:46:25 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// allocate dynamic memory

// DESCRIPTION :
// The ft_calloc() function allocates memory for an array of nmemb elements
// of size bytes each and returns a pointer to the allocated memory.
// The memory is set to zero.
// If nmemb or size is 0, then ft_calloc() returns either NULL, 
// or a unique pointer value that can later be
// successfully passed to free()
// If the multiplication of nmemb and size would result in integer overflow,
// then ft_calloc() returns an error.
// By contrast, an integer overflow would not be detected
// in the following call to malloc(),
// with the result that an incorrectly sized block of memory would be allocated:
// malloc(nmemb * size);

// RETURN VALUE :
// The ft_calloc() function return a pointer to the allocated memory,
// which is suitably aligned for any built-in type.
// On error, this function return NULL.
// NULL may also be returned by a successful call to
// ft_calloc() with nmemb or size equal to zero
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	memory = (void *) malloc(nmemb * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, nmemb * size);
	return (memory);
}
