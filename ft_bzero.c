/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:26:30 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 09:20:35 by juduchar         ###   ########.fr       */
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
