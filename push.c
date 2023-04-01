/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:40:59 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/31 15:49:28 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size;
	if (b->size > 0)
	{
		while (i > 0)
		{
			a->arr[i] = a->arr[i - 1];
			i--;
		}
		a->size++;
		i = 0;
		a->arr[0] = b->arr[0];
		while (++i < b->size)
		{
			b->arr[i-1] = b->arr[i];
		}
		b->size--;
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
    int i;

	i = b->size;
	if (a->size > 0)
	{
		while (i > 0)
		{
			b->arr[i] = b->arr[i - 1];
			i--;
		}
		b->size++;
		i = 0;
		b->arr[0] = a->arr[0];
		while (++i < a->size)
		{
			a->arr[i-1] = a->arr[i];
		}
		a->size--;
		ft_printf("pb\n");
	}
}
