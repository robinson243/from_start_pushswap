/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 20:10:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/28 14:25:10 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+     +#+           */
/*   Created: 2025/07/25 20:10:23 by romukena          #+#    #+#             */
/*   Updated: 2025/07/28 18:45:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void partition_a(t_stack *s, t_partition *p) {
    t_node *current = s->a;
    int i = 0;
    
    p->pushed = 0;
    p->rotated = 0;
    while (current && i++ < p->size) {
        if (current->data <= p->pivot) {
            pb(s);
            p->pushed++;
        } else {
            ra(s);
            p->rotated++;
        }
        current = s->a;
    }
}

static void partition_b(t_stack *s, t_partition *p) {
    t_node *current = s->b;
    int i = 0;
    
    p->pushed = 0;
    p->rotated = 0;
    while (current && i++ < p->size) {
        if (current->data >= p->pivot) {
            pa(s);
            p->pushed++;
        } else {
            rb(s);
            p->rotated++;
        }
        current = s->b;
    }
}

void hybrid_sort(t_stack *s, int size, int is_stack_a) {
    if (size <= 3) {
        if (is_stack_a) handle_small_a(s, size);
        else handle_small_b(s, size);
        return;
    }
    
    t_partition p;
    p.size = size;
    p.pivot = is_stack_a ? 
        get_pivot(s->a, size) : 
        get_pivot(s->b, size);
    
    if (is_stack_a) partition_a(s, &p);
    else partition_b(s, &p);
    
    // Annuler les rotations
    int i = 0;
    while (is_stack_a && i++ < p.rotated && s->size_a > 1)
        rra(s);
    i = 0;
    while (!is_stack_a && i++ < p.rotated && s->size_b > 1)
        rrb(s);
    
    // Trier récursivement les partitions
    if (is_stack_a) {
        hybrid_sort(s, p.rotated, 1);
        hybrid_sort(s, p.pushed, 0);
    } else {
        hybrid_sort(s, p.pushed, 1);
        hybrid_sort(s, p.rotated, 0);
    }
}

void handle_small_a(t_stack *s, int size) {
    if (size == 2 && s->a->data > s->a->next->data)
        sa(s);
    else if (size == 3)
        sort_three(s);
}

void handle_small_b(t_stack *s, int size) {
    if (size == 1) {
        pa(s);
    } else if (size == 2) {
        if (s->b->data < s->b->next->data)
            sb(s);
        pa(s);
        pa(s);
    } else if (size == 3) {
        sort_three_b(s);
        pa(s);
        pa(s);
        pa(s);
    }
}

void sort_three_b(t_stack *s) {
    const int top = s->b->data;
    const int mid = s->b->next->data;
    const int bot = s->b->next->next->data;

    if (top < mid && mid > bot && top < bot) {
        rb(s);
    } else if (top > mid && mid < bot && top < bot) {
        sb(s);
    } else if (top < mid && mid > bot && top > bot) {
        rrb(s);
    } else if (top > mid && mid < bot && top > bot) {
        sb(s);
        rrb(s);
    } else if (top < mid && mid < bot) {
        sb(s);
        rb(s);
    }
}