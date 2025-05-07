/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:14:05 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/13 12:29:52 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(int ac, char **av)
{
	t_stack	*new;
	int		i;
	int		nb;

	i = 1;
	nb = 0;
	new = NULL;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			new = ft_stack_new(nb);
		else
			ft_stack_add_bottom(&new, ft_stack_new(nb));
		i++;
	}
	return (new);
}

t_stack	*stack_init_split(char **tab)
{
	t_stack	*new;
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	new = NULL;
	while (tab[i])
	{
		nb = ft_atoi(tab[i]);
		if (i == 0)
			new = ft_stack_new(nb);
		else
			ft_stack_add_bottom(&new, ft_stack_new(nb));
		i++;
	}
	free_tab(tab);
	free(tab);
	return (new);
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	best_index_match;

	while (b)
	{
		current_a = a;
		best_index_match = LONG_MAX;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_index_match)
			{
				best_index_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index_match == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	stack_len_a;
	int	stack_len_b;

	stack_len_a = ft_stack_size(a);
	stack_len_b = ft_stack_size(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(b->above_median))
			b->push_price = stack_len_b - (b->current_position);
		if (b->target->above_median)
			b->push_price += b->target->current_position;
		else
			b->push_price += stack_len_a - (b->target->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*current;
	long	min_price;	

	if (stack == NULL)
		return ;
	min_price = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < min_price)
		{
			min_price = stack->push_price;
			current = stack;
		}
		stack = stack->next;
	}
	current->cheapest = true;
}
