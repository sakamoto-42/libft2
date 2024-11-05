/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:00:35 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 09:22:19 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// checks whether c is a 7-bit unsigned char value that fits into
// the ASCII character set
// (ASCII standard table)
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
