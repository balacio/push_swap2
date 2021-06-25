/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joagosti <joagosti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 19:19:01 by joagosti          #+#    #+#             */
/*   Updated: 2021/06/08 09:28:58 by joagosti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_word_count(char *str, char c)
{
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			w++;
		while (str[i] && (str[i] != c))
			i++;
	}
	return (w);
}

char	*ft_add_word(char **str, char c)
{
	int		len;
	char	*word;
	int		i;

	len = 0;
	while (str[0][len] && (str[0][len] != c))
		len++;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (0);
	i = 0;
	while (str[0][0] && (str[0][0] != c))
	{
		word[i] = str[0][0];
		i++;
		(str[0])++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**wt;
	size_t	wnb;
	size_t	wc;

	wnb = ft_word_count((char *)s, c);
	wt = malloc((wnb + 1) * sizeof(char *));
	if (!wt)
		return (0);
	wc = 0;
	while (wc < wnb)
	{
		while (s[0] && s[0] == c)
			s++;
		wt[wc] = ft_add_word((char **)&s, c);
		if (!(wt[wc]))
			return (0);
		wc++;
	}
	wt[wnb] = 0;
	return (wt);
}
