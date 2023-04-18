/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:06:48 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/16 20:37:18 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort_stack_a(t_stack *a, t_stack *b, int a_size, int i)
{
	while (a_size > 0)
	{
		if (((a->rank[0] >> i) & 1) == 1)
			ra(a);
		else if (is_sort(a) == 0 && is_r(b) == 0)
			break ;
		else
			pb (a, b);
		a_size--;
	}
}

void	radix_sort_stack_b(t_stack *a, t_stack *b, int b_size, int i)
{
	int	bit;
	int	a_size;

	bit = 1;
	a_size = a->size;
	while (a_size > 1)
	{
		a_size /= 2;
		bit++;
	}
	while (b_size > 0 && i <= bit)
	{
		if (((b->rank[0] >> i) & 1) == 1)
			pa(a, b);
		else if (is_sort(a) == 0 && is_r(b) == 0)
			break ;
		else
			rb(b);
		b_size--;
	}
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	a_size;

	i = 0;
	while (i <= 10)
	{
		a_size = a->size;
		radix_sort_stack_a(a, b, a_size, i);
		radix_sort_stack_b(a, b, b->size, i + 1);
		i++;
	}
	while (b->size > 0)
		pa(a, b);
}
