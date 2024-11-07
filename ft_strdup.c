/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:51:59 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 08:56:22 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// duplicate a string

// DESCRIPTION :
// The ft_strdup() function returns a pointer to a new string
// which is a duplicate of the string s
// Memory for the new string is obtained with malloc, and can be freed with free

// RETURN VALUE :
// On success, the ft_strdup() function returns a pointer to the duplicated string
// It returns NULL if insufficient memory was available,
// with errno set to indicate the cause of the error

// ERRORS :
// ENOMEM Insufficient memory available to allocate duplicate string.
char	*strdup(const char *s)
{
	
}