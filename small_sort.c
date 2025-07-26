/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:19:13 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 19:34:22 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack)
{
	sa(stack);
}

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->a->data;
	b = stack->a->next->data;
	c = stack->a->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

int	find_min_pos(t_node *a)
{
	int		pos;
	int		min_pos;
	int		min_val;
	t_node	*current;

	pos = 0;
	min_pos = 0;
	current = a;
	if (!a)
		return (-1);
	min_val = a->data;
	while (current)
	{
		if (current->data < min_val)
		{
			min_val = current->data;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	push_smallest_to_b(t_stack *stack)
{
	int	min_pos;
	int	i;

	i = 0;
	while (i < 2)
	{
		min_pos = find_min_pos(stack->a);
		if (min_pos <= stack->size_a / 2)
		{
			while (min_pos-- > 0)
				ra(stack);
		}
		else
		{
			min_pos = stack->size_a - min_pos;
			while (min_pos-- > 0)
				rra(stack);
		}
		pb(stack);
		i++;
	}
}

void	sort_five(t_stack *stack)
{
	if (stack->size_a == 5)
		push_smallest_to_b(stack);
	sort_three(stack);
	pa(stack);
	pa(stack);
}
