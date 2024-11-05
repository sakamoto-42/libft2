/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:02:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/05 20:59:42 by julien           ###   ########.fr       */
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
	int	passed;

	passed = 1;
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
			passed = 0;
		}
		/*else
			printf("Success at %d (%c) :\nExpected : %d\nGot: %d\n\n",
				i, (char)i, res_tester, res_tested);
		*/
		i++;
	}
	if (!passed)
		return (0);
	return (1);
}

int	ft_to_tester(int (*ft_tested)(int i), int (*ft_tester)(int i))
{
	int	i;
	int	res_tested;
	int	res_tester;
	int	passed;

	passed = 1;
	i = 0;
	while (i <= 255)
	{
		res_tested = ft_tested(i);
		res_tester = ft_tester(i);
		if (res_tested != res_tester)
		{
			printf("Error at %d (%c) :\nExpected : %d\nGot: %d\n\n",
				i, (char)i, res_tester, res_tested);
			passed = 0;
		}
		/*
		else
		{
			printf("Success at %d (%c) :\nExpected : %d\nGot: %d\n\n",
				i, (char)i, res_tester, res_tested);
		}
		*/
		i++;
	}
	if (!passed)
		return (0);
	return (1);
}

void	ft_free_tab(char **str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
	}
	free(str);
}

int	ft_strlen_tester(void)
{
	char	**str;
	int		i;
	int		res_tested;
	int		res_tester;
	int		passed;

	passed = 1;
	str = malloc(9 * sizeof(char *));
	if (!str)
		return (0);
	str[0] = malloc((11 + 1) * sizeof(char));
	if (!str[0])
	{
		free(str);
		return (0);
	}
	strcpy(str[0], "Hello world");
	str[1] = malloc((1 + 1) * sizeof(char));
	if (!str[1])
	{
		ft_free_tab(str, 1);
		return (0);
	}
	strcpy(str[1], "a");
	str[2] = malloc((2 + 1) * sizeof(char));
	if (!str[2])
	{
		ft_free_tab(str, 2);
		return (0);
	}
	strcpy(str[2], "42");
	str[3] = malloc((13 + 1) * sizeof(char));
	if (!str[3])
	{
		ft_free_tab(str, 3);
		return (0);
	}
	strcpy(str[3], "Hello\nworld");
	str[4] = malloc((13 + 1) * sizeof(char));
	if (!str[4])
	{
		ft_free_tab(str, 4);
		return (0);
	}
	memcpy(str[4], "Hello\nworld\0", 13);
	str[5] = malloc((0 + 1) * sizeof(char));
	if (!str[5])
	{
		ft_free_tab(str, 5);
		return (0);
	}
	strcpy(str[5], "");
	str[6] = malloc((1 + 1) * sizeof(char));
	if (!str[6])
	{
		ft_free_tab(str, 6);
		return (0);
	}
	memcpy(str[6], "\0\0", 2);
	str[7] = malloc((13 + 1) * sizeof(char));
	if (!str[7])
	{
		ft_free_tab(str, 7);
		return (0);
	}
	strcpy(str[7], "Hello\tworld");
	str[8] = malloc((7 * 4  + 1) * sizeof(char));
	if (!str[8])
	{
		ft_free_tab(str, 8);
		return (0);
	}
	strcpy(str[8], "平仮名ひらがな");
	str[9] = malloc((16 * 4 + 1) * sizeof(char));
	if (!str[9])
	{
		ft_free_tab(str, 9);
		return (0);
	}
	strcpy(str[9], "àâäçéèêëîïôöùûüÿ");
	i = 0;
	while (i <= 9)
	{
		res_tested = ft_strlen(str[i]);
		res_tester = strlen(str[i]);
		if (res_tested != res_tester)
		{
			printf("Error at %d (%s) :\nExpected : %d\nGot: %d\n\n",
				i, str[i], res_tester, res_tested);
			passed = 0;
		}
		else
		{
			printf("Success at %d (%s) :\nExpected : %d\nGot: %d\n\n",
				i, str[i], res_tester, res_tested);
		}
		i++;
	}
	//free(str);
	if (!passed)
		return (0);
	return (1);
}

char	*ft_src_init(const char *str, int n)
{
	char	*src;

	src = malloc((n + 1) * sizeof(char));
	if (!src)
		return (NULL);
	strcpy(src, str);
	return (src);
}

int ft_memset_tester()
{
	char	*src_tested;
	char	*src_tester;
	char	c;
	size_t	n;
	int		passed;

	passed = 1;
	n = 3;
	c = 'Z';
	src_tested = ft_src_init("AAAAA", 5);
	if (!src_tested)
		return (0);
	src_tested = ft_memset(src_tested, c, n);
	src_tester = ft_src_init("AAAAA", 5);
	if (!src_tester)
		return (0);
	src_tester = memset(src_tester, c, n);
	if (strcmp(src_tested, src_tester) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", src_tested, src_tester);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			src_tested, src_tester);
	//free(src_tested);
	//free(src_tester);
	if (!passed)
		return (0);
	return (1);
}

void	ft_print_memory(char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		printf("%02x", str[i]);
		i++;
	}
}

int ft_bzero_tester()
{
	char	*src_tested;
	char	*src_tester;
	size_t	n;
	int		passed;

	passed = 1;
	n = 3;
	src_tested = ft_src_init("AAAAA", 5);
	ft_bzero(src_tested, n);
	src_tester = ft_src_init("AAAAA", 5);
	bzero(src_tester, n);
	if (strcmp(src_tested, src_tester) != 0)
	{
		printf("Error\nExpected : ");
		ft_print_memory(src_tested, 5);
		printf("\nGot : ");
		ft_print_memory(src_tester, 5);
		passed = 0;
	}
	else
	{
		printf("Success\nExpected : ");
		ft_print_memory(src_tested, 5);
		printf("\nGot : ");
		ft_print_memory(src_tester, 5);
		printf("\n\n");
	}
	//free(src_tested);
	//free(src_tester);
	if (!passed)
		return (0);
	return (1);
}

int ft_memcpy_tester()
{
	char	*src;
	char	*dest_tested;
	char	*dest_tester;
	size_t	n;
	int		passed;

	passed = 1;
	n = 3;
	src = ft_src_init("AAAAA", 5);
	dest_tested = malloc((5 + 1) * sizeof(char));
	if (!dest_tested)
		return (0);
	dest_tested = ft_memcpy(dest_tested, src, n);
	dest_tester = malloc((5 + 1) * sizeof(char));
	if (!dest_tester)
		return (0);
	dest_tester = memcpy(dest_tester, src, n);
	if (strcmp(dest_tested, dest_tester) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", dest_tested, dest_tester);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			dest_tested, dest_tester);
	//free(dest_tested);
	//free(dest_tester);
	if (!passed)
		return (0);
	return (1);
}

int ft_memmove_tester()
{
	char	*src;
	char	*dest_tested;
	char	*dest_tester;
	char	*dest_tested_overlap;
	char	*dest_tester_overlap;
	int		passed;
	size_t	n;

	passed = 1;
	n = 5;
	src = ft_src_init("Hello, world!", 13);
	dest_tested = malloc((5 + 1) * sizeof(char));
	if (!dest_tested)
		return (0);
	dest_tested = ft_memmove(dest_tested, src, n);
	dest_tester = malloc((5 + 1) * sizeof(char));
	if (!dest_tester)
		return (0);
	dest_tester = memmove(dest_tester, src, n);
	if (strcmp(dest_tested, dest_tester) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", dest_tested, dest_tester);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			dest_tested, dest_tester);
	//free(dest_tested);
	//free(dest_tester);
	dest_tested_overlap = src + 7;
	dest_tested_overlap = ft_memmove(dest_tested_overlap, src, n);
	dest_tester_overlap = src + 7;
	dest_tester_overlap = memmove(dest_tester_overlap, src, n);
	if (strcmp(dest_tested_overlap, dest_tester_overlap) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n",
			dest_tested_overlap, dest_tester_overlap);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			dest_tested_overlap, dest_tester_overlap);
	//free(dest_tested_overlap);
	//free(dest_tester_overlap);
	if (!passed)
		return (0);
	return (1);
}

int	ft_strlcpy_tester()
{
	char	*src;
	char	*dest_tested;
	size_t	strlcpy_result_tested;
	char	*dest_tester;
	size_t	strlcpy_result_tester;
	char	*dest_tested_zero;
	size_t	strlcpy_result_tested_zero;
	char	*dest_tester_zero;
	size_t	strlcpy_result_tester_zero;
	int		passed;
	size_t	n;

	passed = 1;
	n = 6;
	src = ft_src_init("Hello, world!", 13);
	dest_tested = malloc((5 + 1) * sizeof(char));
	if (!dest_tested)
		return (0);
	strlcpy_result_tested = ft_strlcpy(dest_tested, src, n);
	dest_tester = malloc((5 + 1) * sizeof(char));
	if (!dest_tester)
		return (0);
	strlcpy_result_tester = strlcpy(dest_tester, src, n);
	if (strcmp(dest_tested, dest_tester) != 0
		&& strlcpy_result_tested == strlcpy_result_tester)
	{
		printf("Error :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcpy_result_tested, dest_tested,
			strlcpy_result_tester, dest_tester);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcpy_result_tested, dest_tested,
			strlcpy_result_tester, dest_tester);
	//free(dest_tested);
	//free(dest_tester);
	dest_tested_zero = malloc((0 + 1) * sizeof(char));
	if (!dest_tested_zero)
		return (0);
	strlcpy_result_tested_zero = ft_strlcpy(dest_tested_zero, src, 0);
	dest_tester_zero = malloc((0 + 1) * sizeof(char));
	if (!dest_tester_zero)
		return (0);
	strlcpy_result_tester_zero = strlcpy(dest_tester_zero, src, 0);
	if (strcmp(dest_tested_zero, dest_tester_zero) != 0
		&& strlcpy_result_tested_zero == strlcpy_result_tester_zero)
	{
		printf("Error :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcpy_result_tested_zero, dest_tested_zero,
			strlcpy_result_tester_zero, dest_tester_zero);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcpy_result_tested_zero, dest_tested_zero,
			strlcpy_result_tester_zero, dest_tester_zero);
	//ree(dest_tested_zero);
	//free(dest_tester_zero);
	if (!passed)
		return (0);
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
	else if (strcmp(ft_name, "memset") == 0)
		res = ft_memset_tester();
	else if (strcmp(ft_name, "bzero") == 0)
		res = ft_bzero_tester();
	else if (strcmp(ft_name, "memcpy") == 0)
		res = ft_memcpy_tester();
	else if (strcmp(ft_name, "memmove") == 0)
		res = ft_memmove_tester();
	else if (strcmp(ft_name, "strlcpy") == 0)
		res = ft_strlcpy_tester();
	/*
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
	ft_main_tester("memset");
	ft_main_tester("bzero");
	ft_main_tester("memcpy");
	ft_main_tester("memmove");
	ft_main_tester("strlcpy");
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
