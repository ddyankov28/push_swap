/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:18 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 11:22:49 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	size;
	int	flag;
	int	*rank;
}		t_stack;

void	ft_error(t_stack *a, t_stack *b);
void	check_args(int ac, char **av, t_stack *a, t_stack *b);
void	check_doubles(t_stack *a, t_stack *b);
void	get_size(char **av, t_stack *a);
void	ft_swap(int *a, int *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	sort_three(t_stack *a);
void	sort_four(t_stack *a, t_stack *b);
void	sort_five(t_stack *a, t_stack *b);
int		modified_atoi(const char *str, t_stack *a);
int		find_idx(t_stack *a);
int		is_sorted(t_stack *a);
void	find_rank(t_stack *a, t_stack *b);
void	radix_sort(t_stack *a, t_stack *b);
void	ft_error(t_stack *a, t_stack *b);
void	end_free(t_stack *a, t_stack *b);
void	start_sorting(t_stack *a, t_stack *b);

#endif