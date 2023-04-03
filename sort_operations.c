/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:43:26 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/03 18:10:21 by ddyankov         ###   ########.fr       */
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

void    sa(t_stack *a)
{
	if (a->size >= 1)
     {
		ft_swap(&a->arr[0],&a->arr[1]);
		ft_printf("sa\n");
	 }	
}

void	sb(t_stack *b)
{
	if (b->size > 1)
	{
		ft_swap(&b->arr[0],&b->arr[1]);
		ft_printf("sb\n");
	}
}


