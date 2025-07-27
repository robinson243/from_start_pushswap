/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:08:59 by romukena          #+#    #+#             */
/*   Updated: 2025/07/27 03:33:53 by romukena         ###   ########.fr       */
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

void	free_all(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	current = stack->a;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	
	current = stack->b;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}

/* int	main(int argc, char **argv)
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
	if (stack->size_a == 2)
		sort_two(stack);
	else if (stack->size_a == 3)
		sort_three(stack);
	else if (stack->size_a == 4 || stack->size_a == 5)
		sort_five(stack);
	else
		quicksort_a(stack, stack->size_a);
	print_stacks(stack);
	free_all(stack);
	return (0);
} */

int main(void) {
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack) return 1;
    
    // Initialisation
    stack->a = NULL;
    stack->b = NULL;
    stack->size_a = 0;
    stack->size_b = 0;

    // Valeurs de test pour la pile A (ordre inverse)
     int values[] = {100, 15, 78, 92, 3, 45, 60, 23, 88, 17, 
                    55, 32, 70, 8, 41, 66, 29, 50, 84, 5};
    int size = sizeof(values) / sizeof(values[0]);
    
    // Remplissage de la pile A
    for (int i = size - 1; i >= 0; i--) {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node) return 1;
        new_node->data = values[i];
        new_node->next = stack->a;
        stack->a = new_node;
        stack->size_a++;
    }

    // Affichage avant tri
    printf("=== AVANT QUICKSORT_A ===\n");
    print_stack(stack->a);
    print_stack(stack->b);
    printf("Taille A: %d, Taille B: %d\n\n", stack->size_a, stack->size_b);
    
    // Tri principal
    quicksort_a(stack, stack->size_a);
    
    // Affichage après tri
    printf("=== APRES QUICKSORT_A ===\n");
    print_stack(stack->a);
    print_stack(stack->b);
    printf("Taille A: %d, Taille B: %d\n", stack->size_a, stack->size_b);

    // Libération mémoire
    t_node *tmp;
    while (stack->a) {
        tmp = stack->a;
        stack->a = stack->a->next;
        free(tmp);
    }
    free(stack);
    return 0;
}