/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:31:17 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/13 17:56:00 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*	creeune nouvelle liste avec la value = nb	*/
t_stack	*ft_stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->value = nb;
	new->current_position = 0;
	new->next = NULL;
	return (new);
}

/*	renvoi le dernier element de la liste	*/
t_stack	*ft_stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*	renvoi l'avant dernier element de la liste	*/
t_stack	*ft_before_last_stack(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

/*	ajoute un element a la fin de stack	*/
void	ft_stack_add_bottom(t_stack	**stack, t_stack *new)
{
	t_stack	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = ft_stack_last(*stack);
	tail->next = new;
}

/*	renvoi la taille de stack ou 0 si !stack	*/
int	ft_stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
