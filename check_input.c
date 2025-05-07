/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:44:22 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/13 13:33:23 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	input_is_number(char *str)
{
	int	i;

	i = 0;
	if (is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && is_number(str[i]))
		i++;
	if (str[i] != '\0' && !is_number(str[i]))
		return (0);
	return (1);
}

static int	check_duplicate(char **av)
{
	int	j;
	int	i;

	i = 1;
	if (!(*av) || !av[0])
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[j])
		{
			if (i != j && ft_strcmp_v2(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_long(long long nb)
{
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}

static int	check_for_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i + 1] != '\0' && is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char **av, int i)
{
	int	nb_zero;

	nb_zero = 0;
	while (av[i])
	{
		if (!input_is_number(av[i]))
			return (0);
		if (check_long(ft_atol_v2(av[i])))
			return (0);
		nb_zero += check_for_zero(av[i]);
		i++;
	}
	if (nb_zero > 1)
		return (0);
	if (check_duplicate(av))
		return (0);
	return (1);
}
