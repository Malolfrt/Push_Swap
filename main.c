/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:08:53 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/13 13:24:23 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		sa(stack_a, false);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

static t_stack	*call_split(char **av)
{
	char	**tab;
	t_stack	*stack;

	tab = ft_split(av[1], ' ');
	if (!tab)
		return (NULL);
	if (!check_input(tab, 0))
	{
		free_tab(tab);
		free(tab);
		ft_error(NULL, NULL);
	}
	stack = stack_init_split(tab);
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	if (ac == 2)
		stack_a = call_split(av);
	else
	{
		if (!check_input(av, 1))
			ft_error(NULL, NULL);
		stack_a = stack_init(ac, av);
	}
	stack_b = NULL;
	stack_size = ft_stack_size(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
