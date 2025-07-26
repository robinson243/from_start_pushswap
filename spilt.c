/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spilt.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 01:51:32 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 14:31:02 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_word(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_charset(str[i], charset))
			i++;
	}
	return (count);
}

static char	*ft_strndup(char *s, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (end - start) + 1);
	if (!dest)
		return (NULL);
	while (start + i < end)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_split(char *s, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(char *) * count_word(s, charset) + 1);
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_charset(s[i], charset))
			i++;
		j = i;
		while (s[i] && !is_charset(s[i], charset))
			i++;
		if (j < i)
		{
			tab[k] = ft_strndup(s, j, i);
			if (!tab[k])
				return (free_tab(tab), NULL);
			k++;
		}
	}
	tab[k] = NULL;
	return (tab);
}
