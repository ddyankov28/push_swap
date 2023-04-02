/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/02 17:13:33 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *a)
{
	int i = 0;
	while (i < a->size - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	ft_printf("Error\n");
	exit(1);
}

void	put_numbers_in_arr(char **av, t_stack *a, t_stack *b)
{
	int i = 1;
	int c;
	int j = 0;
	char **args;
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
	{
    	printf("NO INT\n");
        ft_error(a, b);	
	}
}

int	main(int ac, char **av)
{
	t_stack     *a;
	t_stack     *b;
	int i;

	i = 0;
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a->size = 0;
	b->size = 0;
	a->flag = 0;
	check_args(ac, av);
	get_size(av, a);
	a->arr = malloc(sizeof(int) * (a->size + 1));
	b->arr = malloc(sizeof(int) * (a->size + 1));
	put_numbers_in_arr(av, a, b);
	check_doubles(a, b);
	if (is_sorted(a) == 1)
	{
		sort_three(a);
		sort_four(a, b);
		sort_five(a, b);
	}
	/*for(int i = 0; i < a->size; i++)
		ft_printf("Stack A: %d \t\tStack B: %d\n\n", a->arr[i], b->arr[i]);
	ft_printf("Size of A: %d\nSize of B: %d\n", a->size, b->size);*/
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
	return (0);
}
