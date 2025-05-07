/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:09:41 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/03 01:50:26 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	OPTIMISATION 500 VALEURS	*/
static long	ft_moyenne(t_stack *stack)
{
	long	moyenne;
	int		size;

	moyenne = 0;
	size = ft_stack_size(stack);
	while (stack)
	{
		moyenne += stack->value;
		stack = stack->next;
	}
	moyenne = moyenne / (long)size;
	return (moyenne);
}

/*	OPTIMISATION 500 VALEURS	*/
static void	set_bool(t_stack **stack)
{
	int	moyenne;

	moyenne = ft_moyenne(*stack);
	while (*stack)
	{
		if ((*stack)->value >= moyenne)
			(*stack)->above_moyenne = true;
		else
			(*stack)->above_moyenne = false;
		*stack = (*stack)->next;
	}
}

/*	OPTIMISATION 500 VALEURS	*/
static void	push_all_moyenne(t_stack **a, t_stack **b)
{
	int		size;
	int		nb;
	t_stack	*tmp;

	tmp = *a;
	set_bool(a);
	*a = tmp;
	size = ft_stack_size(*a);
	nb = 0;
	while (nb <= size)
	{
		if ((*a)->above_moyenne == false)
			pb(a, b, false);
		else
			ra(a, false);
		nb++;
	}
	size = ft_stack_size(*a);
	while (size-- > 3)
		pb(a, b, false);
}

static void	push_all_save_three(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	while (size-- > 3)
		pb(a, b, false);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		stack_size;

	stack_size = ft_stack_size(*a);
	if (stack_size >= 100)
		push_all_moyenne(a, b);
	else
		push_all_save_three(a, b);
	sort_three(a);
	while (*b)
	{
		set_stack(*a, *b);
		move_stack(a, b);
	}
	set_position(*a);
	smallest = find_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
