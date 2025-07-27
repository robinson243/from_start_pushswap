/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:50:58 by romukena          #+#    #+#             */
/*   Updated: 2025/07/27 02:18:46 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_node **lst)
{
	t_node	*current;
	t_node	*data_next;

	current = *lst;
	if (!lst || !*lst)
		return ;
	while (current)
	{
		data_next = current->next;
		free(current);
		current = data_next;
	}
	*lst = NULL;
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free_list(&stack->a);
	free_list(&stack->b);
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	free(stack);
}

int	sorted_list(t_node *stack)
{
	t_node	*current;
	t_node	*nextone;

	current = stack;
	nextone = stack;
	if (!stack)
		return (1);
	if (!stack->next)
		return (1);
	while (current)
	{
		nextone = current->next;
		if (nextone && current->data > nextone->data)
			return (0);
		current = current->next;
	}
	return (1);
}

int	check_duplicates(t_node *stack)
{
	t_node	*cur;
	t_node	*nextone;

	cur = stack;
	nextone = stack;
	if (!stack)
		return (0);
	while (cur)
	{
		nextone = cur->next;
		while (nextone)
		{
			if (cur->data == nextone->data)
				return (1);
			nextone = nextone->next;
		}
		cur = cur->next;
	}
	return (0);
}

void	print_stacks(t_stack *stack)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	tmp_a = stack->a;
	tmp_b = stack->b;
	printf("\nPile A :\n");
	while (tmp_a)
	{
		printf("%d\n", tmp_a->data);
		tmp_a = tmp_a->next;
	}
	printf("Taille A : %d\n", stack->size_a);
	printf("\nPile B :\n");
	while (tmp_b)
	{
		printf("%d\n", tmp_b->data);
		tmp_b = tmp_b->next;
	}
	printf("Taille B : %d\n\n", stack->size_b);
}
