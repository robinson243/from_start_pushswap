/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:10:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 18:39:11 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_stack *stack, int size)
{
	int	pivot;
	int	pushed;
	int	remain;

	if (size <= 3)
	{
		if (size == 2 && stack->a->data > stack->a->next->data)
			sa(stack);
		else if (size == 3)
			sort_three(stack);
		return ;
	}
	pivot = get_pivot(stack->a, size);
	pushed = push_below_pivot(&stack->a, &stack->b, stack, pivot);
	if (pushed == 0)
	{
		pb(stack);
		pushed = 1;
	}
	remain = size - pushed;
	quicksort_a(stack, remain);
	quicksort_b(stack, pushed);
}

void	quicksort_b(t_stack *st, int size)
{
	int	push;

	if (size <= 3)
	{
		if (size == 1)
			pa(st);
		else if (size == 2)
		{
			if (st->b->data < st->b->next->data)
				sb(st);
			pa(st);
			pa(st);
		}
		else
		{
			sort_three_b(st);
			pa(st);
			pa(st);
			pa(st);
		}
		return ;
	}
	push = push_above_pivot(&st->b, &st->a, st, get_pivot(st->b, size));
	if (push == 0)
	{
		pa(st);
		push = 1;
	}
	quicksort_a(st, push);
	quicksort_b(st, size - push);
}

int	push_above_pivot(t_node **b, t_node **a, t_stack *stack, int pivot)
{
	int	i;
	int	pushed;
	int	rotated;
	int	size;

	i = 0;
	pushed = 0;
	rotated = 0;
	size = stack->size_b;
	while (i < size)
	{
		if ((*b)->data >= pivot)
		{
			pa(stack);
			pushed++;
		}
		else
		{
			rb(stack);
			rotated++;
		}
		i++;
	}
	while (rotated-- > 0 && stack->b != NULL)
		rrb(stack);
	return (pushed);
}

void	sort_three_b(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !stack->b || !stack->b->next || !stack->b->next->next)
		return ;
	a = stack->b->data;
	b = stack->b->next->data;
	c = stack->b->next->next->data;
	if (a < b && b < c && a < c)
	{
		sb(stack);
		rrb(stack);
	}
	else if (a < b && b > c && a < c)
		rb(stack);
	else if (a > b && b < c && a < c)
		rrb(stack);
	else if (a < b && b > c && a > c)
		sb(stack);
	else if (a > b && b < c && a > c)
	{
		rrb(stack);
		sb(stack);
	}
}
