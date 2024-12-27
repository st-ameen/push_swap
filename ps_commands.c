#include "push_swap.h"

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

static void	reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target, 'a');
	pa(a, b, false);
}

int bigger_than_median(t_stack_node *a, int median)
{
  while (a)
  {
    if (a->value < median)
        return 0;
    a = a->next;
  }
  return 1;
}

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *smallest;
	int len_a;

	len_a = stack_len(*a);
	if (len_a == 5)
		handle_five(a, b);
	int *sorted = stack_to_array(*a);
  	int median = sorted[len_a/2];
  	int q1 = sorted[len_a/4];
	free(sorted);
    
  	while (stack_len(*a) > 3)
  	{
      		if (bigger_than_median(*a, median))
      		{
        		while (stack_len(*a) > 3)
          		pb(b, a, false);
       		 	break;
      		}
      		if ((*a)->value < median)
      		{
       			pb(b, a, false);
        		if ((*b)->value < q1)
          			rb(b, false);
      		}
      		else
        		ra(a, false);
  	}
	tiny_sort(a);
	while (*b)
	{
		init_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
