/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:37:32 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 10:30:01 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for a lowercase character
static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

// convert a lowercase letter to an uppercase letter

// DESCRIPTION :
// If c is a lowercase letter, ft_toupper() returns its uppercase equivalent,
// Otherwise (if c is not a lowercase letter), it returns c

// NOTE :
// If c is neither an unsigned char value nor EOF, the behavior of this
// function is undefined

// RETURN VALUE :
// The value returned is that of the converted letter, 
// or c if the conversion was not possible.
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
