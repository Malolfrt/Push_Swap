/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:23:36 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/07 16:07:21 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (*stack == NULL)
		return ;
	tail = ft_stack_last(*stack);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_stack **stack_a, bool checker)
{
	rotate(stack_a);
	if (checker == false)
		ft_putstr("ra\n");
}

void	rb(t_stack **stack_b, bool checker)
{
	rotate(stack_b);
	if (checker == false)
		ft_putstr("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (checker == false)
		ft_putstr("rr\n");
}
