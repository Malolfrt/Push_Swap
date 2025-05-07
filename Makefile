# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlefort <mlefort@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 21:25:21 by mlefort           #+#    #+#              #
#    Updated: 2024/02/07 19:36:41 by mlefort          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS	= checker

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g3

OBJ_PATH = obj/
SRC_PATH = ./

SRC_FILES	=	main.c \
				ft_split.c \
				check_input.c \
				check_input_utils.c \
				stack_init.c \
				stack_init_utils.c \
				utils.c \
				stack_utils.c \
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				sort.c \
				sort_three.c \
				sort_utils.c \
				move.c

SRC_FILES_BONUS	= 	checker.c \
					checker_utils.c \
					get_next_line.c \
					get_next_line_utils.c \
					ft_split.c \
					check_input.c \
					check_input_utils.c \
					stack_init.c \
					stack_init_utils.c \
					utils.c \
					stack_utils.c \
					push.c \
					swap.c \
					rotate.c \
					reverse_rotate.c

OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJ_FILES_BONUS	= $(SRC_FILES_BONUS:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ_FILES))
OBJS_BONUS	= $(addprefix $(OBJ_PATH), $(OBJ_FILES_BONUS))

all: $(OBJ_PATH) ${NAME}

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH):
		mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


bonus : $(OBJ_PATH) $(BONUS)

${BONUS}: ${OBJS_BONUS}
	${CC} ${CFLAGS} ${OBJS_BONUS} -o ${BONUS}

clean:
	rm -rf *.o ${OBJ_PATH}

fclean: clean
	rm -f ${NAME}
	rm -f ${BONUS}

re: fclean all

.PHONY: all bonus clean fclean re
