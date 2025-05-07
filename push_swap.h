/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:15:03 by mlefort           #+#    #+#             */
/*   Updated: 2024/02/08 14:43:19 by mlefort          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> // write, read...
# include <stdlib.h> // malloc, free...
# include <limits.h> // INT_MAX, INT_MIN...
# include <stdio.h> // remove for push
# include <stdbool.h> // bool

typedef struct s_list
{
	int				value;
	int				current_position;
	int				push_price;
	bool			above_median;
	bool			cheapest;
	bool			above_moyenne;
	struct s_list	*target;
	struct s_list	*next;

}	t_stack;

/*	main.c	*/
int		is_sorted(t_stack *stack);

/*	ft_split.c	*/
char	**ft_split(char *str, char c);

/*	check_input.c	*/
int		check_input(char **av, int i);

/*	check_input_utils.c	*/
int		is_number(char c);
int		is_sign(char c);
int		ft_strcmp_v2(char *s1, char *s2);
long	ft_atol_v2(char *str);

/*	stack_init.c	*/
t_stack	*stack_init(int ac, char **av);
t_stack	*stack_init_split(char **av);
void	set_target(t_stack *a, t_stack *b);
void	set_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);

/*	stack_init_utils.c	*/
int		ft_atoi(char *str);
t_stack	*find_smallest(t_stack *stack);
void	set_position(t_stack *stack);

/*	utils.c	*/
void	ft_error(t_stack **a, t_stack **b);
void	free_stack(t_stack **stack);
void	ft_putstr(char *str);
void	free_tab(char **tab);

/*	stack_utils.c	*/
t_stack	*ft_stack_new(int nb);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
t_stack	*ft_before_last_stack(t_stack *stack);
void	ft_stack_add_bottom(t_stack	**stack, t_stack *new);

/*	MOUVEMENT : push.c/swap.c/rotate.c/reverse_rotate.c	*/
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **a, t_stack **b, bool checker);

void	sa(t_stack **stack_a, bool checker);
void	sb(t_stack **stack_b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);

void	ra(t_stack **stack_a, bool checker);
void	rb(t_stack **stack_b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);

void	rra(t_stack **stack_a, bool checker);
void	rrb(t_stack **stack_b, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);

/*	SORT : sort_three.c/sort_utils.c/sort.c	*/
int		find_highest(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort(t_stack **a, t_stack **b);
void	set_stack(t_stack *a, t_stack *b);

/*	MOVE : move.c	*/
void	move_stack(t_stack **a, t_stack **b);

#endif