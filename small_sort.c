/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:00:17 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/16 18:43:38 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_idx(t_stack *a)
{
	int	idx;
	int	i;

	idx = 0;
	i = 1;
	while (i < a->size)
	{
		if (a->rank[idx] > a->rank[i])
			idx = i;
		i++;
	}
	return (idx);
}

void	sort_three(t_stack *a)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
	{
		if (a->rank[0] > a->rank[1] && a->rank[0] < a->rank[2])
			sa(a);
		else if (a->rank[1] < a->rank[0] && a->rank[1] > a->rank[2])
		{
			sa(a);
			rra(a);
		}
		else if (a->rank[2] > a->rank[1] && a->rank[2] < a->rank[0])
			ra(a);
		else if (a->rank[2] < a->rank[1] && a->rank[2] > a->rank[0])
		{
			sa(a);
			ra(a);
		}
		else if (a->rank[0] < a->rank[1] && a->rank[0] > a->rank[2])
			rra(a);
	}
}

void	sort_four(t_stack *a, t_stack *b)
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
			pb(a, b);
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

void	help_sort_five(t_stack *a, t_stack *b)
{
	rra(a);
	rra(a);
	pb(a, b);
}

void	sort_five(t_stack *a, t_stack *b)
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
			pb(a, b);
		}
		else if (find_idx(a) == 3)
			help_sort_five(a, b);
		else if (find_idx(a) == 4)
		{
			rra(a);
			pb(a, b);
		}
		sort_four(a, b);
		pa(a, b);
	}
}
