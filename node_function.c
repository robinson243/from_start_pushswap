/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:06:26 by romukena          #+#    #+#             */
/*   Updated: 2025/07/25 17:08:41 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

void	push_back(t_node **stack, int data)
{
	t_node	*new;
	t_node	*tmp;

	new = new_node(data);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	push_front(t_node **stack, int data)
{
	t_node	*new;

	new = new_node(data);
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}
