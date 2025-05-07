/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:45:12 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/02 15:44:27 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest(t_stack *stack)
{
	int	highest;

	if (!stack)
		return (0);
	highest = stack->value;
	while (stack)
	{
		if (stack->value > highest)
			highest = stack->value;
		stack = stack->next;
	}
	return (highest);
}

void	set_stack(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
