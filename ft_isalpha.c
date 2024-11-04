/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:21:13 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/04 16:50:46 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int  ft_isupper(char c)
{
    return (c >= 65 && c <= 90);
}

static int  ft_islower(int c)
{
    return (c >= 97 && c <= 122);
}

int ft_isalpha(int c)
{
    return (ft_isupper(c) || ft_islower(c));
}