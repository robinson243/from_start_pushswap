/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:08:59 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 02:22:33 by romukena         ###   ########.fr       */
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
#include "push_swap.h" // adapte le nom à ton projet
int	main(int ac, char **av)
{
	char	**args;
	int		i;

	args = get_args(ac, av);
	if (!args)
	{
		printf("Erreur d'arguments\n");
		return (1);
	}
	i = 0;
	while (args[i])
	{
		printf("args[%d] = %s\n", i, args[i]);
		i++;
	}
	free_tab(args);
	return (0);
}