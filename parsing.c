/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:10:52 by romukena          #+#    #+#             */
/*   Updated: 2025/07/25 18:40:32 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if (c == 32 || c == '\f' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\t' || c == '\v')
		return (1);
	return (0);
}

long	ft_atol(char *s)
{
	int	i;
	int	minus;
	int	res;

	i = 0;
	res = 0;
	minus = 1;
	while (is_space(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			minus *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	return (res * minus);
}
