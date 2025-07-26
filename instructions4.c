/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:24:59 by romukena          #+#    #+#             */
/*   Updated: 2025/07/25 18:40:11 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->a || !stack->a->next)
		return ;
	first = stack->a;
	second = stack->a->next;
	first->next = second->next;
	second->next = first;
	stack->a = second;
}

void	swap_b(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->b || !stack->b->next)
		return ;
	first = stack->b;
	second = stack->b->next;
	first->next = second->next;
	second->next = first;
	stack->b = second;
}

void	rotate_a(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack->a || !stack->a->next)
		return ;
	first = stack->a;
	stack->a = first->next;
	first->next = NULL;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	rotate_b(t_stack *stack)
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
}
