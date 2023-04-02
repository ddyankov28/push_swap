/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:00:17 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/02 23:01:56 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_idx(t_stack *a)
{
    int idx;
    int i;

    idx = 0;
    i = 1;
    while (i < a->size)
    {
        if (a->arr[idx] > a->arr[i])
            idx = i;
        i++;
    }
    return (idx);
}

void    sort_three(t_stack *a)
{
    if (a->size == 2 || a->size == 3)
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
        if (find_idx(a) == 0)
            pb(a, b);
        else if (find_idx(a) == 1)
        {
            sa(a);
            pb(a, b);
        }
        else if (find_idx(a) == 2)
        {
            ra(a);
            sa(a);
            pb(a,b);
        }
        else if (find_idx(a) == 3)
        {
            rra(a);
            pb(a, b);
        }
        sort_three(a);
        pa(a, b);
    }
}

void    sort_five(t_stack *a, t_stack *b)
{
    if (a->size == 5)
    {
        if (find_idx(a) == 0)
            pb(a, b);
        else if (find_idx(a) == 1)
        {
            sa(a);
            pb(a, b);
        }
        else if (find_idx(a) == 2)
        {
            ra(a);
            sa(a);
            pb(a,b);
        }
        else if (find_idx(a) == 3)
        {
            rra(a);
            rra(a);
            pb(a, b);
        }
        else if (find_idx(a) == 4)
        {
            rra(a);
            pb(a, b);
        }       
        sort_four(a, b);
        pa(a, b);
    }
}

void	radix_sort_stack_b(t_stack *a, t_stack *b, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size)
	{
		if (((b->arr[0] >> j) & 1) == 0)
			rb(b);
		else
			pa(a,b);
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = a->size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = a->size;
		while (size--)
		{
			if (((a->arr[0] >> j) & 1) == 0)
				pb(a, b);
			else
                ra(a);
		}
		radix_sort_stack_b(a,b, b->size, bit_size, j + 1);
	}
	while (b->size != 0)
        pa(a,b);
}

