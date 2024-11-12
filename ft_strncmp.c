/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:11:29 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/08 09:16:03 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// compare two strings

// DESCRIPTION :
// The ft_strncmp() function compares the two strings s1 and s2

// The comparison is done using unsigned characters
// ft_strncmp() returns an integer indicating
// the result of the comparison, as follows:
// 0, if the s1 and s2 are equal
// a negative value if s1 is less than s2
// a positive value if s1 is greater than s2

// The ft_strncmp() function compares only
// the first (at most) n bytes of s1 and s2

// RETURN VALUE :
// The ft_strncmp() function return an integer less than,
// equal to, or greater than zero if the first n bytes thereof s1 is found,
// respectively, to be less than, to match, or be greater than s2
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (((unsigned char) *s1 || (unsigned char) *s2) && n--)
	{
		if ((unsigned char) *s1 != (unsigned char) *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
