/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:09:54 by romukena          #+#    #+#             */
/*   Updated: 2025/07/26 02:22:13 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structure de données */
typedef struct s_node
{
	int				data;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*a;
	t_node			*b;
	int				size_a;
	int				size_b;
}					t_stack;

/* Fonctions pour le noeud */
t_node				*new_node(int data);
void				push_back(t_node **stack, int data);
void				push_front(t_node **stack, int data);

/* Initialisation de la stack et un putstr*/
t_stack				*init_stack(int argc, char **argv);
void				ft_putstr(char *str);

/* Parsing */
long				ft_atol(char *s);

/* Instructions */
void				pa(t_stack *stack);
void				pb(t_stack *stack);
void				sb(t_stack *stack);
void				sa(t_stack *stack);
void				ss(t_stack *stack);
void				ra(t_stack *stack);
void				rb(t_stack *stack);
void				rr(t_stack *stack);
void				rra(t_stack *stack);
void				rrb(t_stack *stack);
void				rrr(t_stack *stack);
void				swap_a(t_stack *stack);
void				swap_b(t_stack *stack);
void				rotate_a(t_stack *stack);
void				rotate_b(t_stack *stack);
void				reverse_rotate_a(t_stack *stack);
void				reverse_rotate_b(t_stack *stack);

/* Utils */
int					sorted_list(t_node *stack);
void				free_list(t_node *lst);
void				free_stack(t_stack *stack);
int					check_duplicates(t_node *stack);
void				print_stacks(t_stack *stack);

/* bubblesort et pivot */
int					get_pivot(t_node *stack, int size);
void				bubble_sort(int *tab, int size);

/* small sort */
void				sort_three(t_stack *stack);
void				sort_five(t_stack *stack);
int					find_min_pos(t_node *a);

/* utils2 */
int					get_index(t_node *stack, int value);
void				print_stack(t_node *stack);
int					push_below_pivot(t_node **a, t_node **b, t_stack *stack,
						int pivot);

/* utils big algo */
void	quicksort_a(t_stack *stack, int size);
void	quicksort_b(t_stack *st, int size);
void	sort_three_b(t_stack *stack);
int	push_above_pivot(t_node **b, t_node **a, t_stack *stack, int pivot);

/* ft_utils */

int		ft_strlen(char *str);
char	*ft_strdup(char *str);
/* split */
char	**ft_split(char *s, char *charset);
void	free_tab(char **tab);

/* args */
char	**get_args(int ac, char **av);


#endif