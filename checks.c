/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:58:10 by ddyankov          #+#    #+#             */
/*   Updated: 2023/03/30 12:48:12 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int modified_atoi(const char *str, t_stack *a)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (!ft_isdigit(str[i]))
			a->flag = 1;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		i++;
		if (result * sign > 2147483647 || result * sign < -2147483648)
            a->flag = 1;
	}
	return (result * sign);
}

void	check_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != ' '))
			{
				ft_printf("Error: Wrong Char\n");
				exit(1);
			}
			j++;
		}
	}
}

void	check_doubles(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			if (a->arr[i] == a->arr[j])
            {
                printf("Doubles\n");
                ft_error(a, b);
            }
            j++;
        }
		i++;
	}
}
