/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:12:07 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/09 05:34:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// locate a substring in a string

// DESCRIPTION :
// The ft_strnstr() function locates the first occurrence of
// the null-terminated string little in the string big,
// where not more than len characters are searched
// Characters that appear after a ‘\0’ character are not searched

// RETURN VALUES :
// If little is an empty string, big is returned;
// If little occurs nowhere in big, NULL is returned;
// Otherwise, a pointer to the first character
// of the first occurrence of little is returned
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (!*little)
		return ((char *)big);
	little_len = ft_strlen(little);
	while (*big && len--)
	{
		if (ft_strncmp(big, little, little_len) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
