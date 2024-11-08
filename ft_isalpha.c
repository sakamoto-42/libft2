/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:21:13 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 19:03:58 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks for an uppercase letter
static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

// checks for a lowercase character
static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

// checks for an alphabetic character
// it is equivalent to (ft_isupper(c) || ft_islower(c))
int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
