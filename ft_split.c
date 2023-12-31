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

// If word count is 0, will exit.
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
	if (word_count == 0)
		exit (0);
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

static void	free_arr(char **argv, int i)
{
	ft_free_array(argv, i);
	print_error();
}

char	**ft_split(char *str, char sep)
{
	char	**argv;
	int		word_count;
	int		i;

	i = 0;
	word_count = count_words(str, sep);
	argv = (char **)malloc((sizeof (char *)) * (word_count + 2));
	if (!argv)
		print_error();
	while (i < (word_count + 2))
	{
		if (i == 0 || i == word_count + 1)
			argv[i] = NULL;
		else
		{
			argv[i] = (char *)malloc(sizeof (char)
					* (cal_word_len(str, ' ') + 1));
			if (!argv[i])
				free_arr(argv, i);
			str = insert_word(str, ' ', argv[i]);
		}
		i++;
	}
	return (argv);
}
