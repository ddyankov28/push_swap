/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:10:54 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/16 20:12:28 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sorting(t_stack *a, t_stack *b)
{
	if (is_sort(a) == 1)
	{
		if (a->size > 1 && a->size < 6)
		{
			sort_three(a);
			sort_four(a, b);
			sort_five(a, b);
		}
		else
			radix_sort(a, b);
	}
}
