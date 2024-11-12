/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:05:42 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 06:42:38 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks for white-space characters.
// In "C" these are: space, form-feed ('\f'), newline ('\n'),
// carriage return ('\r'), horizontal tab  ('\t'), 
// and  vertical tab ('\v')
static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

// convert a string to an integer

// DESCRIPTION :
// The ft_atoi() function converts the initial portion of the string
// in nptr to an integer value
// The string may begin with an arbitrary amount of white space
// (as determined by isspace()
// followed by a single optional '+' or '-' sign
// The remainder of the string is converted to an int value
// in the obvious manner,
// stopping at the first character which is not a valid digit
// If there were no digits at all, ft_atoi() returns 0)

// Note : ft_atoi() does not detect errors

// RETURN VALUE :
// The ft_atoi() function returns the result of the conversion,
// unless the value would underflow or overflow.
int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (ft_isspace((int)*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		result = (result * 10) + ((int)(*nptr) - 48);
		nptr++;
	}
	return (sign * result);
}
