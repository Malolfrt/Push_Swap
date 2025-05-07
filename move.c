/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:21 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/02 17:48:14 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*return_cheapest(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = NULL;
	while (stack)
	{
		if (stack->cheapest)
		{
			cheapest = stack;
			break ;
		}
		stack = stack->next;
	}
	return (cheapest);
}

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rr(a, b, false);
	set_position(*a);
	set_position(*b);
}

static void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest && *a != cheapest->target)
		rrr(a, b, false);
	set_position(*a);
	set_position(*b);
}

static void	finish_rotation(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	move_stack(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target->above_median))
		reverse_rotate_both(a, b, cheapest);
	finish_rotation(a, cheapest->target, 'a');
	finish_rotation(b, cheapest, 'b');
	pa(a, b, false);
}
