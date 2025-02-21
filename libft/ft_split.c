/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: navera-m <navera-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:02:21 by navera-m          #+#    #+#             */
/*   Updated: 2025/01/13 19:04:29 by navera-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *s, char c)
{
	int	word_count;
	int	inside;

	word_count = 0;
	inside = 0;
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s != c && inside == 0)
		{
			word_count++;
			inside = 1;
		}
		else if (*s == c)
			inside = 0;
		s++;
	}
	return (word_count);
}

static int	ft_word_len(const char *s, int i, char c)
{
	int	word_len;

	word_len = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i])
	{
		if (s[i] == c)
			return (word_len);
		i++;
		word_len++;
	}
	return (word_len);
}

static void	ft_free(char **s, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(s[i++]);
	}
	free(s);
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		j;
	int		word_len;
	int		start;

	j = 0;
	array = (char **)ft_calloc(sizeof(char const *), ft_count(&s[j], c) + 1);
	if (!array)
		return (NULL);
	start = 0;
	while (j < ft_count(s, c))
	{
		word_len = ft_word_len(s, start, c);
		while (s[start] == c && s[start] != '\0')
			start++;
		if (s[start] != c && s[start] != '\0')
		{
			array[j] = ft_substr(s, start, word_len);
			if (!array[j])
				return (ft_free(array, j), NULL);
			start = start + word_len;
		}
		j++;
	}
	return (array[j] = NULL, array);
}
