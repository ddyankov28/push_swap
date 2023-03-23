
# include "push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    int i = 0;
    if (b->size > 0)
    {
        while (i <= a->size)
        {
            a->arr[i + 1] = a->arr[i];
            i++;
        }
        a->arr[0] = b->arr[0];
        a->size++;
    }
}

void    pb(t_stack *a, t_stack *b)
{
    int i = 0;
    if (a->size > 0)
    {
        while (i <= b->size)
        {
            a->arr[i + 1] = a->arr[i];
            i++;
        }
        a->arr[0] = b->arr[0];
        a->size++;
    }
}