/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:02:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/04 17:31:53 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int ft_ascii_tester(int (*ft_tested)(int i), int (*ft_tester)(int i))
{
    int i;
    int res_tested;
    int res_tester;

    i = 0;
    while (i <= 255)
    {
        if (ft_tested(i) != 0)
            res_tested = 1;
        else
            res_tested = 0;
        if (ft_tester(i) != 0)
            res_tester = 1;
        else
            res_tester = 0;
        if (res_tested != res_tester)
        {
            printf("Error at %d :\nExpected : %d\nGot: %d\n\n", i, res_tester, res_tested);
            return (0);
        }
        i++;
    }
    return (1);
}

int main(void)
{
    printf("test isdigit :\n");
    if (ft_ascii_tester(ft_isdigit, isdigit))
        printf("SUCCESS\n");
    else
        printf("FAILED\n");
    printf("test finished\n");
}