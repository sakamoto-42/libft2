/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:02:00 by julien            #+#    #+#             */
/*   Updated: 2024/11/05 21:32:28 by julien           ###   ########.fr       */
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

/*
EXAMPLES
       The  following  sets  the pointer ptr to NULL, because only the first 4
       characters of largestring are searched:

             const char *largestring = "Foo Bar Baz";
             const char *smallstring = "Bar";
             char *ptr;

             ptr = strnstr(largestring, smallstring, 4);
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	(void) big;
	(void) little;
	(void) len;
	return (NULL);
}
