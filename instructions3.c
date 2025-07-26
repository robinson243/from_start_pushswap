/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:57:53 by romukena          #+#    #+#             */
/*   Updated: 2025/07/25 18:39:42 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack *stack)
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
	ft_putstr("sb\n");
}

void	ss(t_stack *stack)
{
	swap_a(stack);
	swap_b(stack);
	ft_putstr("ss\n");
}

void	rr(t_stack *stack)
{
	rotate_a(stack);
	rotate_b(stack);
	ft_putstr("rr\n");
}

void	rrr(t_stack *stack)
{
	reverse_rotate_a(stack);
	reverse_rotate_b(stack);
	ft_putstr("rrr\n");
}
