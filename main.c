/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:02:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/04 22:03:06 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <strings.h>
#include <bsd/string.h>
#include <stdlib.h>

int	ft_ascii_tester(int (*ft_tested)(int i), int (*ft_tester)(int i))
{
	int	i;
	int	res_tested;
	int	res_tester;

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
			printf("Error at %d (%c) :\nExpected : %d\nGot: %d\n\n",
				i, (char)i, res_tester, res_tested);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_to_tester(int (*ft_tested)(int i), int (*ft_tester)(int i))
{
	int	i;
	int	res_tested;
	int	res_tester;

	i = 0;
	while (i <= 255)
	{
		res_tested = ft_tested(i);
		res_tester = ft_tester(i);
		if (res_tested != res_tester)
		{
			printf("Error at %d (%c) :\nExpected : %d\nGot: %d\n\n",
				i, (char)i, res_tester, res_tested);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_strlen_tester(void)
{
	char	*str[] = {
		"Hello world",
		"a",
		"42",
		"Hello\nworld",
		"Hello\0world",
		"",
		"\0"
		"Hello\tworld",
		"😀😃😁😂🤣😃😄😅😆😉😊😋😎😍🥰😘😗😙😚🙂🤗🤩🥳🤔🤨😐😑😶🙄😏😣😥😮🤐😯😪😫😴😌😛😜😝🤤😒😓🥲😔😕🙃🤑😲☹🙁😖😞😟🥹😤😢😭😦😧😨😩🤯😬😰😱😳🤪😵😡😠🤬😷🤒🤕🤢🤮🤧😇🤠🤥🤫🤭🧐🤓😈👿🤡👹👺💀☠👻👽👾🤖💩😺😸😹😻😼😽🙀😿😾🙈🙉🙊🫠☺️🤪🥴🥺😶‍🌫️🫥🫣🥱🤔🫡🤨😮‍💨😤🫤😕😵‍💫🫨🥶🥵🥸",
		"平仮名ひらがな",
		"àâäçéèêëîïôöùûüÿ"
	};
	int		i;
	int		res_tested;
	int		res_tester;

	i = 0;
	while (i < 11)
	{
		res_tested = ft_strlen(str[i]);
		res_tester = strlen(str[i]);
		if (res_tested != res_tester)
		{
			printf("Error at %d (%s) :\nExpected : %d\nGot: %d\n\n",
				i, str[i], res_tester, res_tested);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_main_tester(char *ft_name)
{
	int	res;

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
	else if (strcmp(ft_name, "strlen") == 0)
		res = ft_strlen_tester();
	/*
	else if (strcmp(ft_name, "memset") == 0)
		res = ft_tester(ft_memset, memset);
	else if (strcmp(ft_name, "bzero") == 0)
		res = ft_tester(ft_bzero, bzero);
	else if (strcmp(ft_name, "memcpy") == 0)
		res = ft_tester(ft_memcpy, memcpy);
	else if (strcmp(ft_name, "memmove") == 0)
		res = ft_tester(ft_memmove, memmove);
	else if (strcmp(ft_name, "strlcpy") == 0)
		res = ft_tester(ft_strlcpy, strlcpy);
	else if (strcmp(ft_name, "strlcat") == 0)
		res = ft_tester(ft_strlcat, strlcat);
	*/
	else if (strcmp(ft_name, "toupper") == 0)
		res = ft_to_tester(ft_toupper, toupper);
	else if (strcmp(ft_name, "tolower") == 0)
		res = ft_to_tester(ft_tolower, tolower);
	/*
	else if (strcmp(ft_name, "strchr") == 0)
		res = ft_tester(ft_strchr, strchr);
	else if (strcmp(ft_name, "strrchr") == 0)
		res = ft_tester(ft_strrchr, strrchr);
	else if (strcmp(ft_name, "strncmp") == 0)
		res = ft_tester(ft_strncmp, strncmp);
	else if (strcmp(ft_name, "memchr") == 0)
		res = ft_tester(ft_memchr, memchr);
	else if (strcmp(ft_name, "memcmp") == 0)
		res = ft_tester(ft_memcmp, memcmp);
	else if (strcmp(ft_name, "strnstr") == 0)
		res = ft_tester(ft_strnstr, strnstr);
	else if (strcmp(ft_name, "atoi") == 0)
		res = ft_tester(ft_atoi, atoi);
	*/
	if (res)
		printf("SUCCESS\n");
	else
		printf("FAILED\n");
	printf("test finished\n\n");
}

int	main(void)
{
	ft_main_tester("isalpha");
	ft_main_tester("isdigit");
	ft_main_tester("isalnum");
	ft_main_tester("isascii");
	ft_main_tester("isprint");
	ft_main_tester("strlen");
	// test with buff size > n (signal ?), return NULL if param NULL ?
	//ft_main_tester("memset");
	// idem but with 0 (same test but with 0 ?)
	//ft_main_tester("bzero");
	// test zith NULL vals, with or without overlap, buff size > n (signal ?)
	//ft_main_tester("memcpy");
	// overlap + return NULL if one or two vals are NULL, buff size > n (signal ?)
	//ft_main_tester("memmove");
	// test with all combs
	//ft_main_tester("strlcpy");
	// idem
	//ft_main_tester("strlcat");
	ft_main_tester("toupper");
	ft_main_tester("tolower");
	//ft_main_tester("strchr");
	//ft_main_tester("strrchr");
	//ft_main_tester("strncmp");
	//ft_main_tester("memchr");
	//ft_main_tester("memcmp");
	//ft_main_tester("strnstr");
	//ft_main_tester("atoi");
}
