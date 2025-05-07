/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:25:45 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/02 17:46:02 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

/*	prend le 1er element de b et tu met dans a	*/
void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(b, a);
	if (checker == false)
		ft_putstr("pa\n");
}

/*	prend le 1er element de a et tu met dans b	*/
void	pb(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (checker == false)
		ft_putstr("pb\n");
}
