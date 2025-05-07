/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:37:29 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/02 17:43:05 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	sa(t_stack **stack_a, bool checker)
{
	swap(stack_a);
	if (checker == false)
		ft_putstr("sa\n");
}

void	sb(t_stack **stack_b, bool checker)
{
	swap(stack_b);
	if (checker == false)
		ft_putstr("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool checker)
{
	swap(a);
	swap(b);
	if (checker == false)
		ft_putstr("ss\n");
}
