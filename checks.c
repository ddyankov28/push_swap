/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:58:10 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 15:58:14 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	modified_atoi2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	modified_atoi(const char *str, t_stack *a)
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

void	check_args(int ac, char **av, t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (modified_atoi2(av[i]) == 1)
			{
				free(a);
				free(b);
				ft_printf("Error\n");
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
				ft_error(a, b);
			j++;
		}
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->rank[i] > a->rank[i + 1])
			return (1);
		i++;
	}
	return (0);
}
