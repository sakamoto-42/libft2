/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:59:01 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 09:21:16 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks for an alphanumeric character
// it is equivalent to (ft_isalpha(c) || ft_isdigit(c))
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
