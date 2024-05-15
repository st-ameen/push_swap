#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
    t_list *new;
    t_list *elements;

    new = NULL;
    while (lst && f)
    {
        elements = ft_lstnew(f(lst->content));
        if (!elements)
        {
            ft_lstclear(&new, del);
            return (NULL);
        }
        ft_lstadd_back(&new, elements);
        lst = lst->next;
    }
    return new;
}