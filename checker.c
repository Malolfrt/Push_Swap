/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:12:27 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/13 12:49:33 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	is_sorted_v2(t_stack *stack)
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

static void	ft_write_ok_ko(t_stack *stack, int len)
{
	int	size;

	size = ft_stack_size(stack);
	if (is_sorted_v2(stack) && size == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

static t_stack	*checker_input(char **av, int ac)
{
	t_stack	*stack;
	char	**tab;

	if (ac == 2)
	{
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
	}
	else
	{
		if (!check_input(av, 1))
			ft_error(NULL, NULL);
		stack = stack_init(ac, av);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;
	char	*line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	stack_a = checker_input(av, ac);
	len = ft_stack_size(stack_a);
	line = get_next_line(0);
	while (line)
	{
		match_op(&stack_a, &stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	ft_write_ok_ko(stack_a, len);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
