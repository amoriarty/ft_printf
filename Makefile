# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/13 12:17:39 by alegent           #+#    #+#              #
#    Updated: 2016/07/19 12:39:01 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a

SRC_PATH= sources/
SRC_NAME= ft_printf.c \
		  conversion/itoa_base.c \
		  conversion/itoa_base_long.c \
		  conversion/itoa_base_long_long.c \
		  conversion/uitoa_base.c \
		  conversion/uitoa_base_long.c \
		  conversion/uitoa_base_long_long.c \
		  parsing/get_modifier.c \
		  parsing/get_opt.c \
		  parsing/get_precision.c \
		  parsing/get_type.c \
		  parsing/get_weight.c \
		  parsing/parsing.c \
		  print/print_char.c \
		  print/print_minus_weight.c \
		  print/print_n_char.c \
		  print/print_str.c \
		  print/print_weight.c \
		  reading/read_binary.c \
		  reading/read_char.c \
		  reading/read_flag.c \
		  reading/read_hexa.c \
		  reading/read_int.c \
		  reading/read_node.c \
		  reading/read_octal.c \
		  reading/read_ptr.c \
		  reading/read_str.c \
		  reading/read_uint.c \
		  tools/isin.c \
		  tools/islower_case.c \
		  tools/upcase_str.c

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

GCC= clang -Wall -Wextra -Werror
GOPT = -g -O0

INC_LIB= libft/
INC_PATH= .
INC= -I $(INC_LIB) -I $(INC_PATH)

LIB= libft/libft.a
LIBOBJ= `find libft/obj -type f`

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(INC_LIB)
	@ar rc $(NAME) $(OBJ) $(LIBOBJ)
	@echo "Your library is ready to go !"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)/{conversion,parsing,print,reading,tools}
	$(GCC) $(GOPT) $(INC) -o $@ -c $<

clean:
	@make -C $(INC_LIB) clean
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "Object files has been deleted"

fclean: clean
	@make -C $(INC_LIB) fclean
	@rm -rf $(SUBNAME)
	@rm -rf $(NAME)
	@rm -rf main_test show_test 2> /dev/null
	@echo "Librairy has been deleted"

re: fclean all

.PHONY: clean fclean re norme

