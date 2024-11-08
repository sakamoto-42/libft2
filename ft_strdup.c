/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:51:59 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/08 09:13:38 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// duplicate a string

// DESCRIPTION :
// The ft_strdup() function returns a pointer to a new string
// which is a duplicate of the string s
// Memory for the new string is obtained with malloc, and can be freed with free

// RETURN VALUE :
// On success, the ft_strdup() function returns a pointer
// to the duplicated string
// It returns NULL if insufficient memory was available,
// with errno set to indicate the cause of the error

// ERRORS :
// ENOMEM Insufficient memory available to allocate duplicate string.
char	*ft_strdup(const char *s)
{
	size_t	str_len;
	char	*dup;

	str_len = ft_strlen(s);
	dup = (char *) malloc((str_len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, str_len + 1);
	return (dup);
}
