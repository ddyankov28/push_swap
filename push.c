
# include "push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    int i = a->size + 1;
    if (b->size > 0)
    {
        while (i > 0)
        {
            a->arr[i] = a->arr[i - 1];
            i--;
        }
        a->size++;
        i = 0;
        a->arr[0] = a->arr[0];
        while (i < b->size)
        {
            b->arr[i] = b->arr[i + 1];
            i++;
        }
        b->size--;
        ft_printf("pa\n");
    }
}

void    pb(t_stack *a, t_stack *b)
{
    int i = b->size + 1;
    if (a->size > 0)
    {
        while (i > 0)
        {
            b->arr[i] = b->arr[i - 1];
            i--;
        }
        b->size++;
        i = 0;
        b->arr[0] = a->arr[0];
        while (i < a->size)
        {
            a->arr[i] = a->arr[i + 1];
            i++;
        }
        a->size--;
        ft_printf("pb\n");
    }
}