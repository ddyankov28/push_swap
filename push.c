/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:40:59 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/04 14:50:49 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	i = a->size + 1;
	if (b->size > 0)
	{
		while (i > 0)
		{
			a->rank[i] = a->rank[i - 1];
			i--;
		}
		a->size++;
		i = 0;
		a->rank[0] = b->rank[0];
		while (i < b->size)
		{
			b->rank[i] = b->rank[i + 1];
			i++;
		}
		b->size--;
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
    int i;

	i = b->size + 1;
	if (a->size > 0)
	{
		while (i > 0)
		{
			b->rank[i] = b->rank[i-1];
			i--;
		}
		b->size++;
		i = 0;
		b->rank[0] = a->rank[0];
		while (i < a->size)
		{
			a->rank[i] = a->rank[i + 1];
			i++;
		}
		a->size--;
		ft_printf("pb\n");
	}
}
