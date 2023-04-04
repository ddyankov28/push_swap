/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_rank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:12:30 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/04 15:17:32 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_rank(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int rank;
    
    i = 0;
    a->rank = malloc(sizeof(int) * (a->size + 1));
    b->rank = malloc(sizeof(int) * (a->size + 1));
    while (i < a->size)
    {
        rank = 1;
        j = 0;
        while(j < a->size)
        {
            if (a->arr[j] < a->arr[i])
                rank++;
            j++;
        }
        a->rank[i] = rank;
        i++;
    }
}
