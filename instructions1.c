/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:30:16 by romukena          #+#    #+#             */
/*   Updated: 2025/07/25 18:36:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack)
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
	ft_putstr("sa\n");
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (!stack->a)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = stack->b;
	stack->b = tmp;
	stack->size_a--;
	stack->size_b++;
	ft_putstr("pb\n");
}

void	ra(t_stack *stack)
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
	ft_putstr("ra\n");
}

void	rra(t_stack *stack)
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
	ft_putstr("rra\n");
}
