/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 02:11:30 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 03:19:17 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**get_args(int ac, char **av)
{
	int		i;
	char	**args;

	i = 0;
	if (ac <= 1)
		return (NULL);
	if (ac == 2)
		return (ft_split(av[1], " "));
	else
	{
		args = malloc(sizeof(char *) * (ac));
		if (!args)
			return (NULL);
		while (i < (ac - 1))
		{
			args[i] = ft_strdup(av[i + 1]);
			if (!args[i])
				return (free_tab(args), NULL);
			i++;
		}
		args[i] = NULL;
	}
	return (args);
}
