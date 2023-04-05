/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:42:05 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 11:26:49 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	ft_printf("Error\n");
	exit(1);
}

void	end_free(t_stack *a, t_stack *b)
{
	free(a->rank);
	free(b->rank);
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
}
