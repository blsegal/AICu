# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/03 10:59:19 by blsegal           #+#    #+#              #
#    Updated: 2018/02/04 19:22:56 by tbailly-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alum1
SRC = .
INC = .
OBJ = .

LIST_SRC = \
				$(SRC)/main.c       \
				$(SRC)/ft_add_row.c       \
				$(SRC)/ft_next_round.c       \
				$(SRC)/play.c       \
				$(SRC)/ft_refresh_visu.c       \
				$(SRC)/utils.c       \

LIST_OBJ = $(LIST_SRC:$(SRC)/%.c=$(OBJ)/%.o)
CFLAG = -g -Wall -Werror -Wextra
LIBFT = libft.a
LIBFTPATH = ./libft/
INC_LIBFTPATH = $(LIBFTPATH)includes

all : $(NAME)

$(NAME) : $(LIST_SRC)
	make -C $(LIBFTPATH)
	gcc $(CFLAG) -I $(INC) -I $(INC_LIBFTPATH) $(LIST_SRC) -L $(LIBFTPATH) -lft -o $(NAME)

clean :
	make clean -C $(LIBFTPATH)
	/bin/rm -f $(LIST_OBJ)

fclean : clean
	make fclean -C $(LIBFTPATH)
	/bin/rm -f $(NAME)

re : fclean all
