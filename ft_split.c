/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:15:49 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/07 20:18:20 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *str, char c)
{
	int	count;
	int	len;

	count = 0;
	len = 0;
	while (str[len])
	{
		while (str[len] && str[len] == c)
			len++;
		if (str[len] && str[len] != c)
			count++;
		while (str[len] && str[len] != c)
			len++;
	}
	return (count);
}

static char	*cpy_in_tab(char *str, char c)
{
	int		len;
	int		i;
	char	*new_str;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static char	*free_tab_split(char **new, char *str, char c, int i)
{
	new[i] = cpy_in_tab(str, c);
	if (!new[i])
	{
		free_tab(new);
		free(new);
		return (NULL);
	}
	return (new[i]);
}

char	**ft_split(char *str, char c)
{
	char	**new;
	int		size;
	int		i;

	if (!str)
		return (NULL);
	size = count_word(str, c);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		while (*str && *str == c)
			str++;
		if (*str && *str != c)
			new[i] = free_tab_split(new, str, c, i);
		while (*str && *str != c)
			str++;
		i++;
	}
	new[i] = NULL;
	return (new);
}
