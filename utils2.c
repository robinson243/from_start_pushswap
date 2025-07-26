/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:12:17 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 19:59:07 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_below_pivot(t_node **a, t_node **b, t_stack *stack, int pivot)
{
	int	i;
	int	pushed;
	int	rotated;
	int	size;

	i = 0;
	pushed = 0;
	rotated = 0;
	size = stack->size_a;
	while (i++ < size && stack->size_a > 0)
	{
		if ((*a)->data <= pivot)
		{
			pb(stack);
			pushed++;
		}
		else
		{
			ra(stack);
			rotated++;
		}
	}
	while (rotated-- > 0 && stack->a != NULL)
		rra(stack);
	return (pushed);
}

int	get_index(t_node *stack, int value)
{
	int		index;
	t_node	*current;

	index = 0;
	current = stack;
	while (current)
	{
		if (current->data == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

void	print_stack(t_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->data);
		stack = stack->next;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
