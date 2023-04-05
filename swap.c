/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:43:26 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 12:16:45 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	sa(t_stack *a)
{
	if (a->size >= 1)
	{
		ft_swap(&a->rank[0], &a->rank[1]);
		ft_printf("sa\n");
	}
}

void	sb(t_stack *b)
{
	if (b->size > 1)
	{
		ft_swap(&b->rank[0], &b->rank[1]);
		ft_printf("sb\n");
	}
}
