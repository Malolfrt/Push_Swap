/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:34:32 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/07 16:07:00 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (*stack == NULL)
		return ;
	tail = ft_stack_last(*stack);
	before_tail = ft_before_last_stack(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	rra(t_stack **stack_a, bool checker)
{
	reverse_rotate(stack_a);
	if (checker == false)
		ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b, bool checker)
{
	reverse_rotate(stack_b);
	if (checker == false)
		ft_putstr("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (checker == false)
		ft_putstr("rrr\n");
}
