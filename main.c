/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:02:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/04 18:55:26 by juduchar         ###   ########.fr       */
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

void ft_main_ascii_tester(char   *ft_name)
{
    int res;

    printf("test %s :\n", ft_name);
    if (strcmp(ft_name, "isalpha") == 0)
        res = ft_ascii_tester(ft_isalpha, isalpha);
    else if (strcmp(ft_name, "isdigit") == 0)
        res = ft_ascii_tester(ft_isdigit, isdigit);
    else if (strcmp(ft_name, "isalnum") == 0)
        res = ft_ascii_tester(ft_isalnum, isalnum);
    else if (strcmp(ft_name, "isascii") == 0)
        res = ft_ascii_tester(ft_isascii, isascii);
    else if (strcmp(ft_name, "isprint") == 0)
        res = ft_ascii_tester(ft_isprint, isprint);
    if (res)
        printf("SUCCESS\n");
    else
        printf("FAILED\n");
    printf("test finished\n\n");
}

int main(void)
{
    ft_main_ascii_tester("isalpha");
    ft_main_ascii_tester("isdigit");
    ft_main_ascii_tester("isalnum");
    ft_main_ascii_tester("isascii");
    ft_main_ascii_tester("isprint");
    // TODO
    // test strlen
    // test memset
    // test bzero
    // test memcpy
    // test toupper
    // test tolower
    // memmove
    // strlcpy
    // strlcat
    // strchr
    // strrchr
    // strncmp
    // memchr
    // memcmp
    // strnstr
    // atoi
}