/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyster <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:15:26 by soyster           #+#    #+#             */
/*   Updated: 2019/05/01 17:58:30 by soyster          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t		count_word;
	size_t		i;

	count_word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count_word++;
		i++;
	}
	return (count_word);
}

static size_t	ft_c_l(char const *s, size_t i, char c)
{
	size_t		count_letters;

	count_letters = 0;
	while (s[i] != c)
	{
		count_letters++;
		if (s[i + 1] == '\0')
			return (count_letters);
		i++;
	}
	return (count_letters);
}

static char		*ft_fill_str(char const *s, size_t i, char *tab, size_t n_l)
{
	size_t		index;

	index = 0;
	while (index < n_l)
	{
		tab[index] = s[i];
		index++;
		i++;
	}
	tab[index] = '\0';
	return (tab);
}

static char		*ft_last_line(char **tab, size_t count_lines)
{
	tab[count_lines] = NULL;
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	size_t		j;
	size_t		i;

	if (!s)
		return (0);
	if (!(tab = (char**)malloc(sizeof(char*) * (ft_count_word(s, c) + 1))))
		return (0);
	j = 0;
	i = 0;
	while (j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		if (!(tab[j] = (char*)malloc(sizeof(char) * (ft_c_l(s, i, c) + 1))))
		{
			ft_free(tab, j);
			return (0);
		}
		ft_fill_str(s, i, tab[j], ft_c_l(s, i, c));
		i = i + ft_c_l(s, i, c);
		j++;
	}
	ft_last_line(tab, j);
	return (tab);
}
