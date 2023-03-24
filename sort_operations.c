

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void    sa(t_stack *a)
{
    ft_swap(&a->arr[0],&a->arr[1]);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	if (b->size > 1)
	{
		ft_swap(&b->arr[0],&b->arr[1]);
		ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}