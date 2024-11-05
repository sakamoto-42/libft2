/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:29:18 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 17:29:43 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


locate character in string

DESCRIPTION
       The strchr() function returns a pointer to the first occurrence of the character c in the string s.

       The strrchr() function returns a pointer to the last occurrence of the character c in the string s.

       The  strchrnul() function is like strchr() except that if c is not found in s, then it returns a pointer to the null byte at the end of
       s, rather than NULL.

       Here "character" means "byte"; these functions do not work with wide or multibyte characters.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched character or NULL if the character is not found.  The  terminating
       null byte is considered part of the string, so that if c is specified as '\0', these functions return a pointer to the terminator.

       The  strchrnul() function returns a pointer to the matched character, or a pointer to the null byte at the end of s (i.e., s+strlen(s))
       if the character is not found.


char *strrchr(const char *s, int c);