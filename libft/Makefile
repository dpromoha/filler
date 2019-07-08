# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpromoha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 09:36:42 by dpromoha          #+#    #+#              #
#    Updated: 2019/07/03 09:36:49 by dpromoha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

FLAGS	=	-Wall -Werror -Wextra -I./includes

OBJDIR	=	./objects/

PFDIR	=	./sources/ft_printf/

LIBDIR	=	./sources/libft-gnl/

PRINT_F	=	ft_printf.c find_all_expansion.c fwp.c fwp_help.c \
additional_func.c percent_output.c float_output.c number_system.c \
printf_help.c int_output.c to8_output.c unsigned_output.c \
to16_output.c pointer_output.c unicode.c helping_func.c \
unicode_output.c string_output.c float_help.c float_help2.c \

LIBSRC	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_memalloc.c \
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c ft_strstr.c ft_strsub.c ft_strtrim.c \
ft_tolower.c ft_toupper.c ft_itoa.c ft_strnstr.c ft_strsplit.c get_next_line.c reader.c new_file.c \
ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c storage.c twice_free.c \

PFOBJ	=	$(addprefix $(OBJDIR), $(PRINT_F:.c=.o))

LIBOBJ	=	$(addprefix $(OBJDIR), $(LIBSRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJDIR) $(LIBOBJ) $(PFOBJ)
	@ar rcs $(NAME) $(PFOBJ) $(LIBOBJ)
	@echo "made $(NAME)"

$(OBJDIR):
	@mkdir $(OBJDIR)

$(LIBOBJ): $(OBJDIR)%.o : $(LIBDIR)%.c
	@gcc -o $@ -c $< $(FLAGS)

$(PFOBJ): $(OBJDIR)%.o : $(PFDIR)%.c
	@gcc -o $@ -c $< $(FLAGS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
