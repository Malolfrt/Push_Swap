/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:33:45 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/08 14:28:56 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	highest;

	if (is_sorted(*stack))
		return ;
	highest = find_highest(*stack);
	if ((*stack)->value == highest)
		ra(stack, false);
	else if ((*stack)->next->value == highest)
		rra(stack, false);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}
