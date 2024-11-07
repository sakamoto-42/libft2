/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juduchar <juduchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:02:34 by juduchar          #+#    #+#             */
/*   Updated: 2024/11/07 17:44:26 by juduchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

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
	free(str);
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
		printf("Error :\nExpected : %s\nGot: %s\n\n", src_tester, src_tested);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			src_tester, src_tested);
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
		ft_print_memory(src_tester, 5);
		printf("\nGot : ");
		ft_print_memory(src_tested, 5);
		printf("\n\n");
		passed = 0;
	}
	else
	{
		printf("Success\nExpected : ");
		ft_print_memory(src_tester, 5);
		printf("\nGot : ");
		ft_print_memory(src_tested, 5);
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
		printf("Error :\nExpected : %s\nGot: %s\n\n", dest_tester, dest_tested);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			dest_tester, dest_tested);
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
		printf("Error :\nExpected : %s\nGot: %s\n\n", dest_tester, dest_tested);
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
			dest_tester_overlap, dest_tested_overlap);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			dest_tester_overlap, dest_tested_overlap);
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
			strlcpy_result_tester, dest_tester,
			strlcpy_result_tested, dest_tested);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcpy_result_tester, dest_tester,
			strlcpy_result_tested, dest_tested);
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
			strlcpy_result_tester_zero, dest_tester_zero,
			strlcpy_result_tested_zero, dest_tested_zero);
		passed = 0;
	}
	else
		printf("Success :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcpy_result_tester_zero, dest_tester_zero,
			strlcpy_result_tested_zero, dest_tested_zero);
	//free(dest_tested_zero);
	//free(dest_tester_zero);
	if (!passed)
		return (0);
	return (1);
}

int	ft_strchr_strrchr_sub_tester(char *(ft_tested)(const char *, int),
	char *(*ft_tester)(const char *, int), char *src, int c)
{
	char	*dest_tested;
	char	*dest_tester;
	size_t	src_len;

	src_len = strlen(src);
	dest_tested = malloc((src_len + 1) * sizeof(char));
	if (!dest_tested)
		return (0);
	dest_tested = ft_tested(src, c);
	dest_tester = malloc((src_len + 1) * sizeof(char));
	if (!dest_tester)
		return (0);
	dest_tester = ft_tester(src, c);
	if (((dest_tested && dest_tester) && strcmp(dest_tested, dest_tester) != 0)
		|| (dest_tested == NULL && dest_tester != NULL)
		|| (dest_tested != NULL && dest_tester == NULL))
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", dest_tester, dest_tested);
		//free(dest_tested);
		//free(dest_tester);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %s\nGot: %s\n\n",
			dest_tester, dest_tested);
		//free(dest_tested);
		//free(dest_tester);
		return (1);
	}
}

int	ft_strchr_strrchr_tester(char *(ft_tested)(const char *, int),
	char *(*ft_tester)(const char *, int))
{
	int		passed;

	passed = 1;
	passed = ft_strchr_strrchr_sub_tester(ft_tested, ft_tester,
			"Hello, world!", ' ');
	passed = ft_strchr_strrchr_sub_tester(ft_tested, ft_tester,
			"Hello, world!", 'a');
	passed = ft_strchr_strrchr_sub_tester(ft_tested, ft_tester,
			"Hello, world!", 'o');
	passed = ft_strchr_strrchr_sub_tester(ft_tested, ft_tester,
			"", 'a');
	if (!passed)
		return (0);
	return (1);
}

int	ft_memchr_sub_tester(char *src, int c, size_t n)
{
	char	*dest_tested;
	char	*dest_tester;
	size_t	src_len;

	src_len = strlen(src);
	dest_tested = malloc((src_len + 1) * sizeof(char));
	if (!dest_tested)
		return (0);
	dest_tested = ft_memchr(src, c, n);
	dest_tester = malloc((src_len + 1) * sizeof(char));
	if (!dest_tester)
		return (0);
	dest_tester = memchr(src, c, n);
	if (((dest_tested && dest_tester) && strcmp(dest_tested, dest_tester) != 0)
		|| (dest_tested == NULL && dest_tester != NULL)
		|| (dest_tested != NULL && dest_tester == NULL))
	{
		printf("Error\nExpected : ");
		ft_print_memory(dest_tester, n);
		printf("\nGot : ");
		ft_print_memory(dest_tested, n);
		printf("\n\n");
		//free(dest_tested);
		//free(dest_tester);
		return (0);
	}
	else
	{
		printf("Success\nExpected : ");
		if (dest_tested && dest_tester)
			ft_print_memory(dest_tester, n);
		else
			printf("NULL");
		printf("\nGot : ");
		if (dest_tested && dest_tester)
			ft_print_memory(dest_tested, n);
		else
			printf("NULL");
		printf("\n\n");
		//free(dest_tested);
		//free(dest_tester);
		return (1);
	}
}

int	ft_memchr_tester(void)
{
	int		passed;

	passed = 1;
	passed = ft_memchr_sub_tester("Hello, world!", 'H', 0);
	passed = ft_memchr_sub_tester("Hello, world!", '\0', 14);
	passed = ft_memchr_sub_tester("Hello, world!", 'o', 14);
	passed = ft_memchr_sub_tester("Hello, world!", 'a', 14);
	passed = ft_memchr_sub_tester("", 'a', 14);
	if (!passed)
		return (0);
	return (1);
}

int	ft_strncmp_sub_tester(char *s1, char *s2, size_t n)
{
	int	strncmp_result_tested;
	int	strncmp_result_tester;

	strncmp_result_tested = ft_strncmp(s1, s2, n);
	strncmp_result_tester = strncmp(s1, s2, n);
	if (strncmp_result_tested != strncmp_result_tester)
	{
		printf("Error :\nExpected : %d\nGot: %d\n\n",
			strncmp_result_tester, strncmp_result_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %d\nGot: %d\n\n",
			strncmp_result_tester, strncmp_result_tested);
		return (1);
	}
}

int ft_strncmp_tester(void)
{
	int	passed;

	passed = 1;
	passed = ft_strncmp_sub_tester("Hello, world!", "Hello", 0);
	passed = ft_strncmp_sub_tester("Hello, world!", "world", 5);
	passed = ft_strncmp_sub_tester("", "Hello", 5);
	passed = ft_strncmp_sub_tester("Hello", "", 5);
	passed = ft_strncmp_sub_tester("Hello, world!", "Hello, world!", 14);
	passed = ft_strncmp_sub_tester("Hello, world!", "Hello, world!", 13);
	passed = ft_strncmp_sub_tester("Hella, world!", "Hello, world!", 13);
	passed = ft_strncmp_sub_tester("Hello, world!", "Hella, world!", 13);
	passed = ft_strncmp_sub_tester("Hella, world!", "Hello, world!", 4);
	if (!passed)
		return (0);
	return (1);
}

int	ft_strlcat_sub_tester(char *dst, char *src, size_t size)
{
	size_t	strlcat_result_tested;
	size_t	strlcat_result_tester;
	char	*strlcat_dest_tested;
	char	*strlcat_dest_tester;

	strlcat_dest_tested = ft_src_init(dst, ft_strlen(dst));
	strlcat_result_tested = ft_strlcat(strlcat_dest_tested, src, size);
	strlcat_dest_tester = ft_src_init(dst, ft_strlen(dst));
	strlcat_result_tester = strlcat(strlcat_dest_tester, src, size);
	if (strlcat_result_tested != strlcat_result_tester)
	{
		printf("Error :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcat_result_tester, strlcat_dest_tester,
			strlcat_result_tested, strlcat_dest_tested);
		//free(strlcat_dest_tested);
		//free(strlcat_dest_tester);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %ld (%s)\nGot: %ld (%s)\n\n",
			strlcat_result_tester, strlcat_dest_tester,
			strlcat_result_tested, strlcat_dest_tested);
		//free(strlcat_dest_tested);
		//free(strlcat_dest_tester);
		return (1);
	}
}

int	ft_strlcat_tester(void)
{
	int	passed;

	passed = 1;
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 14);
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 0);
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 13);
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 3);
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 4);
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 5);
	passed = ft_strlcat_sub_tester("Hello, ", "world!", 20);
	passed = ft_strlcat_sub_tester("Hello, ", "", 13);
	passed = ft_strlcat_sub_tester("", "world!", 13);
	if (!passed)
		return (0);
	return (1);
}

int	ft_atoi_sub_tester(char *str)
{
	int	atoi_result_tested;
	int	atoi_result_tester;

	atoi_result_tested = ft_atoi(str);
	atoi_result_tester = atoi(str);
	if (atoi_result_tested != atoi_result_tester)
	{
		printf("Error :\nExpected : %d\nGot: %d\n\n",
			atoi_result_tester, atoi_result_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %d\nGot: %d\n\n",
			atoi_result_tester, atoi_result_tested);
		return (1);
	}
}

int	ft_atoi_tester(void)
{
	int	passed;

	passed = 1;
	passed = ft_atoi_sub_tester("");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v-42");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v42");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v-42abcd");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v42abcd");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v42abcd24");
	passed = ft_atoi_sub_tester(" \f\n\r\t\v-42abcd24");
	passed = ft_atoi_sub_tester("0-42");
	passed = ft_atoi_sub_tester("0+42");
	passed = ft_atoi_sub_tester("+42");
	passed = ft_atoi_sub_tester("-42");
	if (!passed)
		return (0);
	return (1);
}

int	ft_memcmp_sub_tester(char *s1, char *s2, size_t n)
{
	int	memcmp_result_tested;
	int	memcmp_result_tester;

	memcmp_result_tested = ft_memcmp(s1, s2, n);
	memcmp_result_tester = memcmp(s1, s2, n);
	if (memcmp_result_tested != memcmp_result_tester)
	{
		printf("Error :\nExpected : %d\nGot: %d\n\n",
			memcmp_result_tester, memcmp_result_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %d\nGot: %d\n\n",
			memcmp_result_tester, memcmp_result_tested);
		return (1);
	}
}

int ft_memcmp_tester(void)
{
	int	passed;

	passed = 1;
	passed = ft_memcmp_sub_tester("Hello, world!", "Hello", 0);
	passed = ft_memcmp_sub_tester("Hello, world!", "world!", 5);
	passed = ft_memcmp_sub_tester("", "Hello", 5);
	passed = ft_memcmp_sub_tester("Hello", "", 5);
	passed = ft_memcmp_sub_tester("Hello, world!", "Hello, world!", 14);
	passed = ft_memcmp_sub_tester("Hello, world!", "Hello, world!", 13);
	passed = ft_memcmp_sub_tester("Hella, world!", "Hello, world!", 13);
	passed = ft_memcmp_sub_tester("Hello, world!", "Hella, world!", 13);
	passed = ft_memcmp_sub_tester("Hella, world!", "Hello, world!", 4);
	if (!passed)
		return (0);
	return (1);
}

int	ft_strnstr_sub_tester(char *big, char *little, size_t len)
{
	char	*strnstr_dest_tested;
	char	*strnstr_dest_tester;

	strnstr_dest_tested = ft_src_init(big, ft_strlen(big));
	strnstr_dest_tested = ft_strnstr(big, little, len);
	strnstr_dest_tester = ft_src_init(big, ft_strlen(big));
	strnstr_dest_tester = strnstr(big, little, len);
	if (((strnstr_dest_tested && strnstr_dest_tester) && strcmp(strnstr_dest_tested, strnstr_dest_tester) != 0)
		|| (strnstr_dest_tested == NULL && strnstr_dest_tester != NULL)
		|| (strnstr_dest_tested != NULL && strnstr_dest_tester == NULL))
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", strnstr_dest_tester, strnstr_dest_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %s\nGot: %s\n\n", strnstr_dest_tester, strnstr_dest_tested);
		return (1);
	}
}

int	ft_strnstr_tester(void)
{
	int	passed;

	passed = 1;
	passed = ft_strnstr_sub_tester("Hello, world!", "Hello", 5);
	passed = ft_strnstr_sub_tester("Hello, world!", "world", 5);
	passed = ft_strnstr_sub_tester("Hello, world!", "world!", 13);
	passed = ft_strnstr_sub_tester("Hello, world ; Hello, world!", "Hello", 28);
	passed = ft_strnstr_sub_tester("Hello, world!", "world", 50);
	passed = ft_strnstr_sub_tester("", "Hello", 5);
	passed = ft_strnstr_sub_tester("Hello", "", 5);
	if (!passed)
		return (0);
	return (1);
}

int	ft_calloc_sub_tester(size_t	nmemb, size_t size)
{
	int		*calloc_memory_tested;
	int		*calloc_memory_tester;
	int		calloc_memory_tested_initialized;
	int		calloc_memory_tester_initialized;
	size_t	i;
	int		res;

	res = 1;
	calloc_memory_tested = (int *)ft_calloc(nmemb * size, sizeof(int));
	if (calloc_memory_tested == NULL)
		return (0);
	calloc_memory_tester = (int *)calloc(nmemb * size, sizeof(int));
	if (calloc_memory_tester == NULL)
		return (0);
	calloc_memory_tested_initialized = 1;
	calloc_memory_tester_initialized = 1;
	i = 0;
	while (i < nmemb * size)
	{
		if (calloc_memory_tested[i] != 0)
			calloc_memory_tested_initialized = 0;
		if (calloc_memory_tester[i] != 0)
			calloc_memory_tester_initialized = 0;
		i++;
	}
	if (calloc_memory_tested_initialized != calloc_memory_tester_initialized)
	{
		printf("Error :\nExpected : Memory initialized : %d\nGot: Memory initialized : %d\n\n",
			calloc_memory_tester_initialized, calloc_memory_tested_initialized);
		res = 0;
	}
	else
		printf("Success :\nExpected : Memory initialized : %d\nGot: Memory initialized : %d\n\n",
			calloc_memory_tester_initialized, calloc_memory_tested_initialized);
	if (memcmp(calloc_memory_tested, calloc_memory_tester, nmemb * size) != 0)
	{
		printf("Error\nExpected :\n");
		ft_print_memory((char *)calloc_memory_tester, nmemb * size);
		printf("\nGot :\n");
		ft_print_memory((char *)calloc_memory_tested, nmemb * size);
		printf("\n\n");
	}
	else
	{
		printf("Success\nExpected :\n");
		if (calloc_memory_tested && calloc_memory_tester)
			ft_print_memory((char *)calloc_memory_tester, nmemb * size);
		else
			printf("NULL");
		printf("\nGot :\n");
		if (calloc_memory_tested && calloc_memory_tester)
			ft_print_memory((char *)calloc_memory_tested, nmemb * size);
		else
			printf("NULL");
		printf("\n\n");
		free(calloc_memory_tested);
		free(calloc_memory_tester);
	}
	if (!res)
		return (0);
	return (1);
}

int	ft_calloc_tester()
{
	int	passed;

	passed = 1;
	passed = ft_calloc_sub_tester(0, 0);
	passed = ft_calloc_sub_tester(1, 1);
	passed = ft_calloc_sub_tester(10, 10);
	if (!passed)
		return (0);
	return (1);
}

int	ft_strdup_sub_tester(char *s)
{
	char	*strdup_dup_tested;
	char	*strdup_dup_tester;

	strdup_dup_tested = ft_strdup(s);
	strdup_dup_tester = strdup(s);
	if (((strdup_dup_tested && strdup_dup_tester) && strcmp(strdup_dup_tested, strdup_dup_tester) != 0)
		|| (strdup_dup_tested == NULL && strdup_dup_tester != NULL)
		|| (strdup_dup_tested != NULL && strdup_dup_tester == NULL))
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", strdup_dup_tester, strdup_dup_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %s\nGot: %s\n\n", strdup_dup_tester, strdup_dup_tested);
		return (1);
	}
}

int	ft_strdup_tester()
{
	int	passed;

	passed = 1;
	passed = ft_strdup_sub_tester("");
	passed = ft_strdup_sub_tester("Hello, world!");
	passed = ft_strdup_sub_tester("Coucou 42");
	if (!passed)
		return (0);
	return (1);
}

int	ft_substr_sub_tester(char const *s, unsigned int start, size_t len, char *expected)
{
	char	*substr_sub_tested;

	substr_sub_tested = ft_substr(s, start, len);
	if (substr_sub_tested == NULL)
		substr_sub_tested = "NULL";
	if (strcmp(substr_sub_tested, expected) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", expected, substr_sub_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %s\nGot: %s\n\n", expected, substr_sub_tested);
		return (1);
	}
	return (1);
}

int	ft_substr_tester()
{
	int	passed;

	passed = 1;
	passed = ft_substr_sub_tester("", 0, 0, "NULL");
	passed = ft_substr_sub_tester("Hello, world!", 0, 0, "NULL");
	passed = ft_substr_sub_tester("Hello, world!", 7, 6, "");
	passed = ft_substr_sub_tester("Hello, world!", 7, 0, "NULL");
	passed = ft_substr_sub_tester("Hello, world!", 0, 5, "Hello");
	passed = ft_substr_sub_tester("Hello, world!", 15, 5, "NULL");
	passed = ft_substr_sub_tester("Hello, world!", 7, 20, "world!");
	passed = ft_substr_sub_tester("Hello, world!", 0, 20, "Hello, world!");
	if (!passed)
		return (0);
	return (1);
}

int	ft_strjoin_sub_tester(char const *s1, char const *s2, char *expected)
{
	char	*subjoin_tested;

	subjoin_tested = ft_strjoin(s1, s2);
	if (subjoin_tested == NULL)
		subjoin_tested = "NULL";
	if (strcmp(subjoin_tested, expected) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", expected, subjoin_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %s\nGot: %s\n\n", expected, subjoin_tested);
		return (1);
	}
	return (1);
}

int	ft_strjoin_tester()
{
	int	passed;

	passed = 1;
	passed = ft_strjoin_sub_tester("", "", "");
	passed = ft_strjoin_sub_tester("Hello", "", "Hello");
	passed = ft_strjoin_sub_tester("", "world", "world");
	passed = ft_strjoin_sub_tester("Hello", ", world!", "Hello, world!");
	if (!passed)
		return (0);
	return (1);
}

int	ft_strtrim_sub_tester(char const *s1, char const *set, char *expected)
{
	char	*subtrim_tested;

	subtrim_tested = ft_strtrim(s1, set);
	if (subtrim_tested == NULL)
		subtrim_tested = "NULL";
	if (strcmp(subtrim_tested, expected) != 0)
	{
		printf("Error :\nExpected : %s\nGot: %s\n\n", expected, subtrim_tested);
		return (0);
	}
	else
	{
		printf("Success :\nExpected : %s\nGot: %s\n\n", expected, subtrim_tested);
		return (1);
	}
	//free(subtrim_tested);
}

int	ft_strtrim_tester()
{
	int	passed;

	passed = 1;
	passed = ft_strtrim_sub_tester("", "", "");
	passed = ft_strtrim_sub_tester("+-+-", "+-", "");
	passed = ft_strtrim_sub_tester("+Hello+", "+", "Hello");
	passed = ft_strtrim_sub_tester("+-Hello+-", "+-", "Hello");
	passed = ft_strtrim_sub_tester("+-Hello+-", "-+", "Hello");
	passed = ft_strtrim_sub_tester("*Hello*", "-+", "*Hello*");
	passed = ft_strtrim_sub_tester("+-+Hel-+-lo-+-", "-+", "Hel-+-lo");
	if (!passed)
		return (0);
	return (1);
}

void	ft_putchar_fd_sub_tester(int c, int fd)
{
	printf("Expected : \n");
	printf("%c", c);
	printf("\nGot: \n");
	ft_putchar_fd(c, fd);
	printf("\n\n");
}

void	ft_putchar_fd_tester(void)
{
	ft_putchar_fd_sub_tester((int)'a', 1);
	ft_putchar_fd_sub_tester((int)'a', 0);
	ft_putchar_fd_sub_tester((int)'0', 1);
	ft_putchar_fd_sub_tester((int)155, 1);
	ft_putchar_fd_sub_tester((int)-155, 1);
	ft_putchar_fd_sub_tester((int)'z', 1);
	ft_putchar_fd_sub_tester((int)'\n', 1);
	ft_putchar_fd_sub_tester((int)'a', 2);
	ft_putchar_fd_sub_tester((int)'0', 2);
	ft_putchar_fd_sub_tester((int)155, 2);
	ft_putchar_fd_sub_tester((int)-155, 2);
	ft_putchar_fd_sub_tester((int)'z', 2);
	ft_putchar_fd_sub_tester((int)'\n', 2);
}

void	ft_putstr_fd_sub_tester(char *s, int fd)
{
	printf("Expected : \n");
	printf("%s", s);
	printf("\nGot: \n");
	ft_putstr_fd(s, fd);
	printf("\n\n");
}

void	ft_putstr_fd_tester(void)
{
	ft_putstr_fd_sub_tester("Hello, World!", 1);
	ft_putstr_fd_sub_tester("Hello, World!", 2);
	ft_putstr_fd_sub_tester("Hello, World!", 0);
	ft_putstr_fd_sub_tester("", 1);
}

void	ft_putendl_fd_sub_tester(char *s, int fd)
{
	printf("Expected : \n");
	printf("%s\n", s);
	printf("\nGot: \n");
	ft_putendl_fd(s, fd);
	printf("\n\n");
}

void	ft_putendl_fd_tester(void)
{
	ft_putendl_fd_sub_tester("Hello, World!", 1);
	ft_putendl_fd_sub_tester("Hello, World!", 2);
	ft_putendl_fd_sub_tester("Hello, World!", 0);
	ft_putendl_fd_sub_tester("", 1);
}

void	ft_putnbr_fd_sub_tester(int n, int fd)
{
	printf("Expected : \n");
	printf("%d", n);
	printf("\nGot: \n");
	ft_putnbr_fd(n, fd);
	printf("\n\n");
}

void	ft_putnbr_fd_tester(void)
{
	ft_putnbr_fd_sub_tester(42, 1);
	ft_putnbr_fd_sub_tester(0, 1);
	ft_putnbr_fd_sub_tester(INT_MIN, 1);
	ft_putnbr_fd_sub_tester(INT_MAX, 1);
	ft_putnbr_fd_sub_tester(-123456, 1);
	ft_putnbr_fd_sub_tester(123456, 1);
	ft_putnbr_fd_sub_tester(42, 2);
	ft_putnbr_fd_sub_tester(0, 2);
	ft_putnbr_fd_sub_tester(INT_MIN, 2);
	ft_putnbr_fd_sub_tester(INT_MAX, 2);
	ft_putnbr_fd_sub_tester(-123456, 2);
	ft_putnbr_fd_sub_tester(123456, 2);
}

void	ft_main_tester(char *ft_name, int *count)
{
	int	res;

	res = 1;
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
	else if (strcmp(ft_name, "strlcat") == 0)
		res = ft_strlcat_tester();
	else if (strcmp(ft_name, "toupper") == 0)
		res = ft_to_tester(ft_toupper, toupper);
	else if (strcmp(ft_name, "tolower") == 0)
		res = ft_to_tester(ft_tolower, tolower);
	else if (strcmp(ft_name, "strchr") == 0)
		res = ft_strchr_strrchr_tester(ft_strchr, strchr);
	else if (strcmp(ft_name, "strrchr") == 0)
		res = ft_strchr_strrchr_tester(ft_strrchr, strrchr);
	else if (strcmp(ft_name, "strncmp") == 0)
		res = ft_strncmp_tester();
	else if (strcmp(ft_name, "memchr") == 0)
		res = ft_memchr_tester();
	else if (strcmp(ft_name, "memcmp") == 0)
		res = ft_memcmp_tester();
	else if (strcmp(ft_name, "strnstr") == 0)
		res = ft_strnstr_tester();
	else if (strcmp(ft_name, "atoi") == 0)
		res = ft_atoi_tester();
	else if (strcmp(ft_name, "calloc") == 0)
		res = ft_calloc_tester();
	else if (strcmp(ft_name, "strdup") == 0)
		res = ft_strdup_tester();
	else if (strcmp(ft_name, "substr") == 0)
		res = ft_substr_tester();
	else if (strcmp(ft_name, "strjoin") == 0)
		res = ft_strjoin_tester();
	else if (strcmp(ft_name, "strtrim") == 0)
		res = ft_strtrim_tester();
	/*
	else if (strcmp(ft_name, "split") == 0)
		res = ft_split_tester();
	else if (strcmp(ft_name, "itoa") == 0)
		res = ft_itoa_tester();
	else if (strcmp(ft_name, "strmapi") == 0)
		res = ft_strmapi_tester();
	else if (strcmp(ft_name, "striteri") == 0)
		res = ft_striteri_tester();
	*/
	else if (strcmp(ft_name, "putchar_fd") == 0)
		ft_putchar_fd_tester();
	else if (strcmp(ft_name, "putstr_fd") == 0)
		ft_putstr_fd_tester();
	else if (strcmp(ft_name, "putendl_fd") == 0)
		ft_putendl_fd_tester();
	else if (strcmp(ft_name, "putnbr_fd") == 0)
		ft_putnbr_fd_tester();
	if (res)
	{
		printf("SUCCESS\n");
		*count = *count + 1;
	}
	else
		printf("FAILED\n");
	printf("test finished\n\n");
}

int	main(void)
{
	int	count;

	count = 0;
	/*
	ft_main_tester("isalpha", &count);
	ft_main_tester("isdigit", &count);
	ft_main_tester("isalnum", &count);
	ft_main_tester("isascii", &count);
	ft_main_tester("isprint", &count);
	ft_main_tester("strlen", &count);
	ft_main_tester("memset", &count);
	ft_main_tester("bzero", &count);
	ft_main_tester("memcpy", &count);
	ft_main_tester("memmove", &count);
	ft_main_tester("strlcpy", &count);
	ft_main_tester("strlcat", &count);
	ft_main_tester("toupper", &count);
	ft_main_tester("tolower", &count);
	ft_main_tester("strchr", &count);
	ft_main_tester("strrchr", &count);
	ft_main_tester("strncmp", &count);
	ft_main_tester("memchr", &count);
	ft_main_tester("memcmp", &count);
	ft_main_tester("strnstr", &count);
	ft_main_tester("atoi", &count);
	ft_main_tester("calloc", &count);
	ft_main_tester("strdup", &count);
	ft_main_tester("substr", &count);
	*/
	//ft_main_tester("strjoin", &count);
	ft_main_tester("strtrim", &count);
	//ft_main_tester("split", &count);
	//ft_main_tester("itoa", &count);
	//ft_main_tester("strmapi", &count);
	//ft_main_tester("striteri", &count);

	//ft_main_tester("putchar_fd", &count);
	//ft_main_tester("putstr_fd", &count);
	//ft_main_tester("putendl_fd", &count);
	//ft_main_tester("putnbr_fd", &count);
	printf("%d/30 tests passed with SUCCESS !\n", count);
}
