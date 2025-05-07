/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:23:44 by mlefort           #+#    #+#             */
/*   Updated: 2024/01/31 18:50:13 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	res;
	int	neg;
	int	i;

	i = 0;
	res = 0;
	neg = 1;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * neg);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (stack)
	{
		if (stack->value < current->value)
			current = stack;
		stack = stack->next;
	}
	return (current);
}

void	set_position(t_stack *stack)
{
	int	i;
	int	stack_len;

	i = 0;
	if (!stack)
		return ;
	stack_len = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->cheapest = false;
		stack->current_position = i;
		if (i <= stack_len)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}
