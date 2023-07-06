/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnishsha <dnishsha@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 09:25:20 by dnishsha          #+#    #+#             */
/*   Updated: 2023/07/06 09:25:23 by dnishsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *str, char sep)
{
	int	word_count;
	int	is_inside_word;

	word_count = 0;
	while (*str)
	{
		is_inside_word = 0;
		while (*str == sep)
			str ++;
		while (*str != sep && *str)
		{
			if (!is_inside_word)
				word_count ++;
			is_inside_word = 1;
			str ++;
		}
	}
	return (word_count);
}

static int	cal_word_len(char *str, char sep)
{
	int	word_len;

	word_len = 0;
	while (*str == sep)
		str ++;
	while (*str != sep && *str)
	{
		word_len ++;
		str ++;
	}
	return (word_len);
}

static char	*insert_word(char *str, char sep, char *argv)
{
	int	i;

	i = 0;
	while (*str == sep)
		str ++;
	while (*str != sep && *str)
	{
		argv[i++] = *str;
		str ++;
	}
	argv[i] = '\0';
	return (str);
}

char	**ft_split(char *str, char sep)
{
	char	**argv;
	int		word_count;
	int		word_len;
	int		i;

	i = 0;
	word_count = count_words(str, sep);
	printf("word_count: %d\n", word_count);
	argv = (char **)malloc((sizeof (char *)) * (word_count + 2));
	if (!argv)
		print_error();
	while (i < (word_count + 2))
	{
		if (i == 0 || i == word_count + 1)
			argv[i] = NULL;
		else
		{
			word_len = cal_word_len(str, ' ');
			printf("word_len: %d\n", word_len);
			argv[i] = (char *)malloc((sizeof (char)) * (word_len + 1));
			if (!argv[i])
			{
				ft_free_array(argv, i);
				print_error();
			}
			str = insert_word(str, ' ', argv[i]);
		}
		i ++;
	}
	return (argv);
}
