#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					value;
	int					current_position;
	int					final;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// extern int ft_putstr_count;

// static inline void ft_putstr(const char *s)
//{
//    int i = 0;
//    while (s[i])
//    {
//        write(1, &s[i], 1);
//        i++;
//    }
//    write(1, "\n", 1);
//    ft_putstr_count++;
//}

char					**ft_split(char *s, char sep);
void					ft_putstr(char *s);
// error handling----------------------------------------------------------------
void					free_stack(t_stack_node **stack);
void					free_matrix(char **argv);
void					error_free(t_stack_node **a, char **argv, bool flag);
int						error_syntax(char *str_nbr);
int						error_repetition(t_stack_node *a, int nbr);
// stack creation-----------------------------------------------------------------------
void					stack_init(t_stack_node **a, char **av, bool flag);
void					init_nodes(t_stack_node *a, t_stack_node *b);
void					set_current_position(t_stack_node *stack);
void					set_price(t_stack_node *a, t_stack_node *b);
void					set_cheapest(t_stack_node *b);
// linked list utils--------------------------------------------------------------------
t_stack_node			*find_last_node(t_stack_node *head);
void					append_node(t_stack_node **stack, int nbr);
t_stack_node			*find_smallest(t_stack_node *stack);
t_stack_node			*return_cheapest(t_stack_node *stack);
int						stack_len(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
void					finish_rotation(t_stack_node **s, t_stack_node *n, char c);
t_stack_node	*find_largest(t_stack_node *stack);
int	*stack_to_array(t_stack_node *stack);
// algorithms---------------------------------------------------------------------------
void					tiny_sort(t_stack_node **a);
void					handle_five(t_stack_node **a, t_stack_node **b);
void					push_swap(t_stack_node **a, t_stack_node **b);
// Commands-----------------------------------------------------------------------------
void					sa(t_stack_node **a, bool checker);
void					sb(t_stack_node **b, bool checker);
void					ss(t_stack_node **a, t_stack_node **b, bool checker);
void					ra(t_stack_node **a, bool checker);
void					rb(t_stack_node **b, bool checker);
void					rr(t_stack_node **a, t_stack_node **b, bool checker);
void					rra(t_stack_node **a, bool checker);
void					rrb(t_stack_node **b, bool checker);
void					rrr(t_stack_node **a, t_stack_node **b, bool checker);
void					pa(t_stack_node **a, t_stack_node **b, bool checker);
void					pb(t_stack_node **b, t_stack_node **a, bool checker);
//-------------------------------------------------------------------------------------
#endif
