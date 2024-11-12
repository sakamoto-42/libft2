/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:44:27 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 10:29:57 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for an uppercase letter
static int	ft_isupper(char c)
{
	return (c >= 65 && c <= 90);
}

// convert an uppercase letter to a lowercase letter

// DESCRIPTION :
// If c is an uppercase letter, ft_tolower() returns its lowercase equivalent,
// Otherwise (if c is not a uppercase letter), it returns c

// NOTE :
// If c is neither an unsigned char value nor EOF, the behavior of this
// function is undefined

// RETURN VALUE :
// The value returned is that of the converted letter, 
// or c if the conversion was not possible.
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	else
		return (c);
}
