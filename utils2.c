/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:12:17 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 01:09:33 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_below_pivot(t_node **a, t_node **b, t_stack *stack, int pivot)
{
	int	i;
	int	pushed;
	int	rotated;

	i = 0;
	pushed = 0;
	rotated = 0;
	while (i < stack->size_a)
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
		i++;
	}
	while (rotated-- > 0)
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
