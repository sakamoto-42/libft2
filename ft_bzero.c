/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:26:30 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/04 20:28:19 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// zero a byte string

// DESCRIPTION :
// The ft_bzero() function erases the data in the n bytes of the memory
// starting at the location pointed to by s, by writing zeros
// (bytes  containing '\0') to that area

// RETURN VALUE :
// None
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
