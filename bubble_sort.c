/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 18:47:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/27 13:03:32 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		swapped = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

int	get_pivot(t_node *stack, int size)
{
	int		*arr;
	t_node	*tmp;
	int		i;
	int		pivot;

	if (!stack || size <= 0)
		return (-1);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	tmp = stack;
	i = 0;
	while (tmp && i < size)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(arr, i);
	pivot = arr[(int)(size * 0.7)];
	free(arr);
	return (pivot);
}

