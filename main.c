/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:55:52 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/16 09:56:14 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
            {
                printf("Error\n");
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
    a->s = malloc(sizeof(int) * a->size);
    int i = 0;
    while (i < ac - 1)
    {
        a->s[i] = ft_atoi(av[i +1]);
        i++;
    }
    i = 0;
    while (i < a->size)
    {
        printf("N[%d]: %d\n",i + 1,a->s[i]);
        i++;
    }
    printf("Size is %d\n", a->size);
    free(a->s);
    free(a);
    free(b);
    return 0;
}