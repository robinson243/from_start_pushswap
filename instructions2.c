/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:42:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/25 18:38:50 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->b || !stack->b->next)
		return ;
	first = stack->b;
	stack->b = first->next;
	first->next = NULL;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->next = first;
	ft_putstr("rb\n");
}

void	rrb(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->b || !stack->b->next)
		return ;
	prev = NULL;
	last = stack->b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->b;
	stack->b = last;
	ft_putstr("rrb\n");
}

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->b)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = stack->a;
	stack->a = tmp;
	stack->size_a++;
	stack->size_b--;
	ft_putstr("pa\n");
}

void	reverse_rotate_a(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->a || !stack->a->next)
		return ;
	prev = NULL;
	last = stack->a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->a;
	stack->a = last;
}

void	reverse_rotate_b(t_stack *stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack->b || !stack->b->next)
		return ;
	prev = NULL;
	last = stack->b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = stack->b;
	stack->b = last;
}
