/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 11:25:25 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_numbers_in_arr(char **av, t_stack *a, t_stack *b)
{
	int		i;
	int		c;
	int		j;
	char	**args;

	i = 1;
	j = 0;
	while (av[i])
	{
		c = 0;
		args = ft_split(av[i], ' ');
		while (args[c])
		{
			a->arr[j] = modified_atoi(args[c], a);
			free(args[c]);
			j++;
			c++;
		}
		free(args);
		i++;
	}
	if (a->flag == 1)
		ft_error(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;
	a->flag = 0;
	check_args(ac, av, a, b);
	get_size(av, a);
	a->arr = malloc(sizeof(int) * (a->size + 1));
	b->arr = malloc(sizeof(int) * (a->size + 1));
	put_numbers_in_arr(av, a, b);
	check_doubles(a, b);
	find_rank(a, b);
	start_sorting(a, b);
	end_free(a, b);
	return (0);
}
