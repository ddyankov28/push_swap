/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:20:03 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 11:24:26 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	i;
	int	temp;

	i = 0;
	temp = a->rank[0];
	while (i < a->size - 1)
	{
		a->rank[i] = a->rank[i + 1];
		i++;
	}
	a->rank[a->size - 1] = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	int	i;
	int	temp;

	i = 0;
	if (b->size > 0)
	{
		temp = b->rank[0];
		while (i < b->size - 1)
		{
			b->rank[i] = b->rank[i + 1];
			i++;
		}
		b->rank[b->size - 1] = temp;
		ft_printf("rb\n");
	}
}
