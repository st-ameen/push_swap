#include "push_swap.h"

int ft_putstr_count = 0;

int main(int argc, char **argv)
{
    t_stack_node *a;
    t_stack_node *b;
    int number = 0;

    a = NULL;
    b = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 1;
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');

    stack_init(&a, argv + 1, argc == 2);
    number = stack_len(a);

    if (!stack_sorted(a))
    {
        if (stack_len(a) == 2)
            sa(&a, false);
        else if (stack_len(a) == 3)
            tiny_sort(&a);
        else
            push_swap(&a, &b);
    }
    printf("arguments: %d\n", number);
    printf("steps: %d\n", ft_putstr_count);
    while (a != NULL)
    {
        printf("%d ", a->value);
        a = a->next;
    }
    printf("\n");
    free_stack(&a);
    return 0;
}