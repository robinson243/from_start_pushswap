/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:08:59 by romukena          #+#    #+#             */
/*   Updated: 2025/07/28 14:21:27 by romukena         ###   ########.fr       */
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
void sort_stack(t_stack *stack) {
    if (sorted_list(stack->a)) return;
    
    /*if (stack->size_a <= 5)
        sort_small(stack);*/
    else
        hybrid_sort(stack, stack->size_a, 1);
}

int main(void) {
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack) return 1;
    
    // Initialisation
    stack->a = NULL;
    stack->b = NULL;
    stack->size_a = 0;
    stack->size_b = 0;

    // Valeurs de test pour la pile A
    int values[] = {100, 15, 78, 92, 3, 45, 60, 23, 88, 17, 
                    55, 32, 70, 8, 41, 66, 29, 50, 84, 5};
    int size = sizeof(values) / sizeof(values[0]);
    
    // Remplissage de la pile A (ordre original)
    for (int i = 0; i < size; i++) {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node) return 1;
        new_node->data = values[i];
        new_node->next = stack->a; // Insertion en tête
        stack->a = new_node;
        stack->size_a++;
    }

    // Affichage avant tri
    printf("=== AVANT TRI ===\n");
    printf("Pile A (%d): ", stack->size_a);
    print_stack(stack->a);
    printf("Pile B (%d): ", stack->size_b);
    print_stack(stack->b);
    
    // Tri principal
   sort_stack(stack);
    
    // Affichage après tri
    printf("\n=== APRÈS TRI ===\n");
    printf("Pile A (%d): ", stack->size_a);
    print_stack(stack->a);
    printf("Pile B (%d): ", stack->size_b);
    print_stack(stack->b);

    // Vérification du tri
    if (sorted_list(stack->a) && stack->size_b == 0)
        printf("\nSUCCÈS : Pile A triée, Pile B vide!\n");
    else
        printf("\nÉCHEC : Tri non réussi!\n");

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

