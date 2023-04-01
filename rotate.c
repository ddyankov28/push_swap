/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:20:03 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/30 13:19:57 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ra(t_stack *a)
{
    int i;
    int temp;
    
    i = 0;
    temp = a->arr[0];
    while (i < a->size - 1)
    {
        a->arr[i] = a->arr[i + 1];
        i++;
    }
    a->arr[a->size - 1] = temp;
    ft_printf("ra\n");
}

void    rb(t_stack *b)
{
    int i;
    int temp;

    i = 0;
    temp = b->arr[0];
    while (i < b->size - 1)
    {
        b->arr[i] = b->arr[i + 1];
        i++;
    }
    b->arr[b->size - 1] = temp;
    ft_printf("rb\n");
}

void    rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    ft_printf("rr\n");
}