/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/24 18:04:17 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	take_args_if_in_strings(char **av, t_stack *a)
{
	int	i;
	int	c;

	i = 1;
	while (av[i])
	{
		a->size--;
		c = 0;
		char **args = ft_split(av[i], ' ');
		while (args[c] != NULL)
		{
			c++;
			a->size++;
		}
		i++;
	}
}

void    check_doubles(t_stack *a,t_stack *b)
{
    int i;
    int j;

    i = 0;
    while (i < a->size)
    {
        j = i + 1;
        while (j < a->size)
        {
            if (a->arr[i] == a->arr[j])
            {
                ft_printf("Error\n");
                free(a->arr);
                free(a);
                free(b);
                exit(1);
            }
            j++;
        }
        i++;
    }
}

void    check_args(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    while(++i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-' &&  av[i][j] != ' ')
            {
                ft_printf("Error\n");
                exit (1);
            }
            j++;
        }
    }
}

void    get_size(int ac, t_stack *a)
{
    int i;

    i = 0;
    while (i < ac - 1)
        i++;
    a->size = i;
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;

    a = (t_stack *)malloc(sizeof(t_stack));
    b = (t_stack *)malloc(sizeof(t_stack));
    a->size = 0;
    b->size = 0;
    get_size(ac, a);
    check_args(ac, av);
    take_args_if_in_strings(av, a);
    printf("Array size is %d\n",a->size);
    exit(0);
    check_doubles(a, b);
    a->arr = malloc(sizeof(int) * a->size);
    b->arr = malloc(sizeof(int) * b->size);
    //sa(a);
    //pb(a, b);
    //pb(a, b);
    //pb(a, b);
    int i = 0;
    while (i < 6)
    {
        ft_printf("Stack A: %d \t\tStack B: %d\n\n",a->arr[i],b->arr[i]);
        i++;
    }
    ft_printf("Size of A: %d\nSize of B: %d\n", a->size, b->size);
    free(a->arr);
    free(a);
    free(b);
    return 0;
}