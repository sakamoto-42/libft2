/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:22:17 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/04 18:50:33 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// fill memory with a constant byte

// DESCRIPTION :
// The ft_memset() function fills the first n bytes of the memory area
// pointed to by s with the constant byte c

// RETURN VALUE
// The ft_memset() function returns a pointer to the memory area s
void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char   *s_ptr;
    size_t  i;

    s_ptr = (unsigned char *) s;
    i = 0;
    while (i < n)
    {
        *s_ptr = c;
        s_ptr++;
    }
    return (s);
}