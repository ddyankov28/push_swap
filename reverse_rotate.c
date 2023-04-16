/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:33:40 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/16 20:11:04 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int	i;
	int	temp;

	i = a->size - 1;
	temp = a->rank[a->size - 1];
	while (i > 0)
	{
		a->rank[i] = a->rank[i - 1];
		i--;
	}
	a->rank[0] = temp;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int	i;
	int	temp;

	i = b->size - 1;
	temp = b->rank[b->size - 1];
	while (i > 0)
	{
		b->rank[i] = b->rank[i - 1];
		i--;
	}
	b->rank[0] = temp;
	ft_printf("rrb\n");
}
int	is_r(t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->size - 1)
	{
		if (b->rank[i] < b->rank[i + 1])
			return (1);
		i++;
	}
	return (0);
}