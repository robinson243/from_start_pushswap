/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:10:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/27 14:21:03 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utils2.c
void	print_stack_state(t_stack *stack, const char *msg, int size,
		char stack_name)
{
	t_node	*node;

	printf("\n--- %s (size: %d, stack: %c) ---\n", msg, size, stack_name);
	printf("Stack A [%d]: ", stack->size_a);
	node = stack->a;
	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\nStack B [%d]: ", stack->size_b);
	node = stack->b;
	while (node)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void	quicksort_a(t_stack *stack, int size)
{
	int	pivot;
	int	pushed;
	int	remain;

    if (size <= 0 || stack->size_a < size) {
        printf("Taille incohérente: size=%d, stack_a_size=%d\n", size, stack->size_a);
        return;
    }
	print_stack_state(stack, "DEBUT quicksort_a", size, 'A');
	if (size <= 3)
	{
		if (size == 2 && stack->a && stack->a->next
			&& stack->a->data > stack->a->next->data)
			sa(stack);
		else if (size == 3)
			sort_three(stack);
		print_stack_state(stack, "DEBUT quicksort_a", size, 'A');
		return ;
	}
	pivot = get_pivot(stack->a, size);
	printf("Pivot A: %d\n", pivot);
	pushed = push_below_pivot(stack, pivot, size);
	printf("Éléments poussés vers B: %d\n", pushed);
	if (pushed == 0)
	{
		pb(stack);
		pushed = 1;
	}
	remain = size - pushed;
	print_stack_state(stack, "APRES push_below_pivot", size, 'A');
	quicksort_a(stack, remain);
	quicksort_b(stack, pushed);
	print_stack_state(stack, "FIN quicksort_a", size, 'A');
}

void	quicksort_b(t_stack *st, int size)
{
	int	push;
	int	pivot;

	print_stack_state(st, "DEBUT quicksort_b", size, 'B');
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
			print_stack_state(st, "FIN quicksort_b (petite taille)", size, 'B');
		}
		return ;
	}
	pivot = get_pivot(st->b, size);
	printf("Pivot B: %d\n", pivot);
	push = push_above_pivot(st, pivot, size);
	printf("Éléments poussés vers A: %d\n", push);
	print_stack_state(st, "APRES push_above_pivot", size, 'B');
	quicksort_a(st, push);
	quicksort_b(st, size - push);
	print_stack_state(st, "FIN quicksort_b", size, 'B');
}

int	push_above_pivot(t_stack *stack, int pivot, int size)
{
	int	i;
	int	pushed;
	int	rotated;

	i = 0;
	pushed = 0;
	rotated = 0;
	while (i < size && stack->b != NULL)
	{
		if (stack->b->data >= pivot)
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
	while (rotated-- && stack->size_b > 1)
		rrb(stack);
	return (pushed);
}

int	push_below_pivot(t_stack *stack, int pivot, int size)
{
	int	i;
	int	pushed;
	int	rotated;

	i = 0;
	pushed = 0;
	rotated = 0;
	while (i < size && stack->a != NULL)
	{
		if (stack->a->data <= pivot)
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
	while (rotated-- > 0 && stack->size_a > 1 && rotated < size)
		rra(stack);
	return (pushed);
}

void sort_three_b(t_stack *stack) {
    int top = stack->b->data;
    int mid = stack->b->next->data;
    int bot = stack->b->next->next->data;

    if (top > mid && mid > bot) return; // Déjà trié
    if (top > mid && mid < bot && top > bot) rb(stack);
    else if (top < mid && mid > bot && top > bot) rrb(stack);
    else if (top > mid && mid < bot && top < bot) sb(stack);
    else if (top < mid && mid < bot) {
        sb(stack);
        rrb(stack);
    }
    else if (top < mid && mid > bot && top < bot) {
        sb(stack);
        rb(stack);
    }
}
