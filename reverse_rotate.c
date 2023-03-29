/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:33:40 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/29 15:48:30 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_stack *a)
{
    int i;
    int temp;

    i = a->size;
    temp = a->arr[a->size - 1];
    while (i > 0)
    {
        a->arr[i] = a->arr[i - 1];
        i--;
    }
    a->arr[0] = temp;
}

void    rrb(t_stack *b)
{
    int i;
    int temp;

    i = b->size;
    temp = b->arr[b->size - 1];
    while (i > 0)
    {
        b->arr[i] = b->arr[i - 1];
        i--;
    }
    b->arr[0] = temp;
}

void    rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}