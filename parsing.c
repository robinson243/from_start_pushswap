/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:10:52 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 03:16:55 by romukena         ###   ########.fr       */
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

int	has_overflow(char *str)
{
	long	num;

	if (!is_valid_number(str))
		return (1);
	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	char	**args;
	t_stack	*stack;
	int		i;

	if (!(args = get_args(argc, argv)) || !*args)
		return (write(2, "Error\n", 6), NULL);
	if (!(stack = malloc(sizeof(t_stack))))
		return (free_tab(args), NULL);
	*stack = (t_stack){NULL, NULL, 0, 0};
	i = -1;
	while (args[++i])
	{
		if (!is_valid_number(args[i]) || has_overflow(args[i]))
			return (free_tab(args), free_stack(stack), write(2, "Error\n", 6), NULL);
		push_back(&stack->a, (int)ft_atol(args[i]));
		stack->size_a++;
	}
	free_tab(args);
	if (check_duplicates(stack->a))
		return (free_stack(stack), write(2, "Error\n", 6), NULL);
	return (stack);
}
