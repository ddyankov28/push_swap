/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:00:17 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/31 14:30:11 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void     pb_small(t_stack *a, t_stack *b)
{
    int i = 1;
    int small = a->arr[0];
    while (i < a->size)
    {
        if (a->arr[i] < small)
        {
            small = a->arr[i];
            ft_swap(&a->arr[0],&a->arr[i]);
        }
        i++;
    }
    pb(a,b);
}

void    sort_three(t_stack *a)
{
    if (a->size < 4)
    {
        if ((a->arr[0] > a->arr[1] && a->arr[0] < a->arr[2]) || a->size == 2)
            sa(a);
        else if (a->arr[1] < a->arr[0] && a->arr[1] > a->arr[2])
        {
            sa(a);
            rra(a);
        }
        else if (a->arr[2] > a->arr[1] && a->arr[2] < a->arr[0])
            ra(a);
        else if (a->arr[2] < a->arr[1] && a->arr[2] > a->arr[0])
        {
            sa(a);
            ra(a);
        }
        else if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2])
            rra(a);
    }
}

void    sort_four(t_stack *a, t_stack *b)
{
    if (a->size == 4)
    {    
        pb_small(a,b);
        sort_three(a);
        pa(a,b);
    }
}

void    sort_five(t_stack *a, t_stack *b)
{
    if (a-> size == 5)
    {
        pb_small(a,b);
        sort_four(a, b);
        pa(a, b);
    }
}

