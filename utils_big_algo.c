/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:10:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/27 03:00:45 by romukena         ###   ########.fr       */
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
			if (size == 2 && stack->a && stack->a->next && stack->a->data > stack->a->next->data)
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
		if (size == 1 && st->b)
			pa(st);
		else if (size == 2 && st->b && st->b->next)
		{
			if (st->b->data < st->b->next->data)
				sb(st);
			pa(st);
			pa(st);
		}
		else if (size == 3 && st->b && st->b->next && st->b->next->next)
		{
			sort_three_b(st);
			pa(st);
			pa(st);
			pa(st);
		}
		return ;
	}
	push = push_above_pivot(&st->b, &st->a, st, get_pivot(st->b, size));
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
	while (i++ < size && stack->size_b > 0 && *b)
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
	}
	while (rotated-- > 0 && stack->b != NULL && stack->size_b > 1)
		rrb(stack);
	return (pushed);
}

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
	while (i++ < size && stack->size_a > 0 && *a)
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
	while (rotated-- > 0 && stack->a != NULL && stack->size_a > 1)
		rra(stack);
	return (pushed);
}

void	sort_three_b(t_stack *stack)
{
	int	top; 
	int	mid; 
	int	bot; 
	
	top = stack->b->data;
	mid = stack->b->next->data;
	bot = stack->b->next->next->data;
	if (top > mid && mid > bot)
		return ;
	else if (top > mid && mid < bot && top > bot)
		rb(stack);
	else if (top < mid && mid > bot && top > bot)
		rrb(stack);
	else if (top > mid && mid < bot && top < bot)
		sb(stack);
	else if (top < mid && mid < bot)
	{
		sb(stack);
		rrb(stack);
	}
	else if (top < mid && mid > bot && top < bot)
	{
		sb(stack);
		rb(stack);
	}
}
