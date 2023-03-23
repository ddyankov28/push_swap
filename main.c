/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvienna <dvienna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/23 14:23:43 by dvienna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    take_args_if_in_strings(char **av, t_stack *a)
{
    int i = 1;
    int c;
    int ar = 0;
    int size = 0;
    while (av[i])
    {
        c = 0;
        char **args = ft_split(av[i], ' ');
        while (args[c] != NULL)
        {
            a->arr[ar] = ft_atoi(args[c]);
            c++;
            ar++;
            size++;
        }
        i++;
    }
    a->size = size;
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
    a->arr = malloc(sizeof(int) * a->size);
    take_args_if_in_strings(av, a);
    check_doubles(a, b);
    //works sa(a);
    int i = 0;
    while (i < a->size)
    {
        ft_printf("%d ",a->arr[i]);
        i++;
    }
    ft_printf("Size is %d\n", a->size);
    free(a->arr);
    free(a);
    free(b);
    return 0;
}