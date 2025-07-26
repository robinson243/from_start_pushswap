/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:08:59 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 20:52:34 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* void print_stack(t_node *stack, char name)
{
    t_node *tmp = stack;
    write(1, "Pile ", 5);
    write(1, &name, 1);
    write(1, " :\n", 3);
    while (tmp)
    {
        char buf[12];
        int len = snprintf(buf, 12, "%d\n", tmp->data);
        write(1, buf, len);
        tmp = tmp->next;
    }
}

void print_stacks(t_stack *stack)
{
    print_stack(stack->a, 'A');
    print_stack(stack->b, 'B');
    write(1, "\n", 1);
}*/

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

/*int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (0);
	stack = parse_arguments(argc, argv);
	if (!stack)
		return (1);
	if (sorted_list(stack->a))
	{
		free_stack(stack);
		return (0);
	}
	quicksort_a(stack, stack->size_a);
	print_stacks(stack);
	free_stack(stack);
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:08:59 by romukena          #+#    #+#             */
/*   Updated: 2025/07/27 19:01:45 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_stack	*stack;
	t_node	*node;
	int		values[] = {7, 2, 9, 4, 5, 1, 8, 3, 6}; // Test values for stack B
	int		size = sizeof(values) / sizeof(values[0]);

	// Create stack
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (1);
	
	// Initialize stack
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	
	// Fill stack B with test values
	for (int i = size - 1; i >= 0; i--)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return (free_stack(stack), 1);
		node->data = values[i];
		node->next = stack->b;
		stack->b = node;
		stack->size_b++;
	}
	
	printf("=== AVANT QUICKSORT_B ===\n");
	printf("Pile B (%d elements):\n", stack->size_b);
	print_stack(stack->b); // Using your existing print_stack from utils2.c
	
	// Execute quicksort_b
	quicksort_b(stack, stack->size_b);
	
	printf("\n=== APRES QUICKSORT_B ===\n");
	printf("Pile A (%d elements):\n", stack->size_a);
	print_stack(stack->a);
	printf("Pile B (%d elements):\n", stack->size_b);
	print_stack(stack->b);
	
	// Cleanup
	free_stack(stack);
	return (0);
}