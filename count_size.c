/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <ddyankov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:51:42 by ddyankov          #+#    #+#             */
/*   Updated: 2023/04/05 11:27:00 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_size(char **av, t_stack *a)
{
	int		i;
	int		c;
	char	**args;

	i = 1;
	while (av[i])
	{
		c = 0;
		args = ft_split(av[i], ' ');
		while (args[c])
		{
			free(args[c]);
			c++;
			a->size++;
		}
		free(args);
		i++;
	}
}
