/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:08:10 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/06 09:08:15 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare memory areas

// DESCRIPTION :
// The ft_memcmp() function compares the first n bytes
// (each interpreted as unsigned char) of the memory areas s1 and s2

// RETURN VALUE :
// The ft_memcmp() function returns an integer
// less than, equal to, or greater than zero
// if the first n bytes of s1 is found, respectively,
// to be less than, to match, or be greater than the first n bytes of s2

// For a nonzero return value, the sign is determined by the sign of the
// difference between the first pair of bytes
// (interpreted as unsigned char) that differ in s1 and s2

// If n is zero, the return value is zero
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	(void) s1;
	(void) s2;
	(void) n;
	return (0);
}
