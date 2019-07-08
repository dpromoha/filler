# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/27 14:35:46 by dpromoha          #+#    #+#              #
#    Updated: 2019/06/27 14:35:49 by dpromoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	dpromoha.filler

FLAGS	=	-Wall -Werror -Wextra -I./includes -I./libft/includes

SRCDIR	=	./sources/

OBJDIR	=	./objects/

LIBDIR	=	./libft/

SRC		=	 what_is_map.c filler.c help_to_count.c look_for.c \
free.c execute_algorithm.c where_to_attack.c around.c piece_overlay.c \
additional_func.c \

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.c=.o))

LIB		=	libftprintf.a

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBDIR)$(LIB)
	@cp $(LIBDIR)$(LIB) ./
	@echo "made the best player $(NAME)"
	@gcc -o $(NAME) $(OBJ) $(LIB) $(FLAGS)

$(OBJ): $(OBJDIR)%.o : $(SRCDIR)%.c
	@gcc -o $@ -c $< $(FLAGS)

$(LIBDIR)$(LIB):
	@make -C $(LIBDIR)

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@make -C $(LIBDIR) clean
	@rm -rf $(OBJ) $(OBJDIR)

fclean:
	@make -C $(LIBDIR) fclean
	@rm -rf $(OBJ) $(OBJDIR)
	@rm -rf $(NAME) $(LIB)

re: fclean $(NAME)

magic:
	@echo "creating magic"
	gcc -Wall -Wextra -Werror ./to_see/take_maps.c ./to_see/magic_result.c ./to_see/magic.c ./libft/libftprintf.a -lncurses -o ./to_see/magic
