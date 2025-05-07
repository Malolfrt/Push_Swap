/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:39:14 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/13 12:56:50 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

static void	ft_clean_all(char *line, t_stack **a, t_stack **b)
{
	free(line);
	ft_error(a, b);
}

void	match_op(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp("sa\n", line) == 0)
		sa(a, true);
	else if (ft_strcmp("sb\n", line) == 0)
		sb(b, true);
	else if (ft_strcmp("ss\n", line) == 0)
		ss(a, b, true);
	else if (ft_strcmp("ra\n", line) == 0)
		ra(a, true);
	else if (ft_strcmp("rb\n", line) == 0)
		rb(b, true);
	else if (ft_strcmp("rr\n", line) == 0)
		rr(a, b, true);
	else if (ft_strcmp("rra\n", line) == 0)
		rra(a, true);
	else if (ft_strcmp("rrb\n", line) == 0)
		rrb(b, true);
	else if (ft_strcmp("rrr\n", line) == 0)
		rrr(a, b, true);
	else if (ft_strcmp("pa\n", line) == 0)
		pa(a, b, true);
	else if (ft_strcmp("pb\n", line) == 0)
		pb(a, b, true);
	else
		ft_clean_all(line, a, b);
}
