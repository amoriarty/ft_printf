# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegent <alegent@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/13 12:17:39 by alegent           #+#    #+#              #
#    Updated: 2015/06/06 15:15:45 by alegent          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#This is a typical Makefile, re-usable anytime you want to compil C project.
#All is in quiet for now, thank to do all the completion that needed for
# specify project

#Define name of program here
NAME= libft.a

#SRC BLOC
# define all the .c file in the variable SRC NAME
SRC_PATH= ./
SRC_NAME= is/ft_isalnum.c \
          is/ft_isalpha.c \
          is/ft_isascii.c \
          is/ft_isblank.c \
          is/ft_isdigit.c \
          is/ft_isprint.c \
          lst/ft_lstadd.c \
          lst/ft_lstdel.c \
          lst/ft_lstdelete.c \
          lst/ft_lstdelone.c \
          lst/ft_lstend.c \
          lst/ft_lstiter.c \
          lst/ft_lstmap.c \
          lst/ft_lstnew.c \
          memory/ft_bzero.c \
          memory/ft_memalloc.c \
          memory/ft_memccpy.c \
          memory/ft_memchr.c \
          memory/ft_memcmp.c \
          memory/ft_memcpy.c \
          memory/ft_memdel.c \
          memory/ft_memmove.c \
          memory/ft_memset.c \
          print/ft_perror.c \
          print/ft_putchar.c \
          print/ft_putchar_fd.c \
          print/ft_putcolor.c \
          print/ft_putcolor_fd.c \
          print/ft_putendl.c \
          print/ft_putendl_fd.c \
          print/ft_puterror.c \
          print/ft_putnbr.c \
          print/ft_putnbr_fd.c \
          print/ft_putstr.c \
          print/ft_putstr_fd.c \
          string/ft_strcat.c \
          string/ft_strchr.c \
          string/ft_strclr.c \
          string/ft_strcmp.c \
          string/ft_strcpy.c \
          string/ft_strdel.c \
          string/ft_strdup.c \
          string/ft_strequ.c \
          string/ft_striter.c \
          string/ft_striteri.c \
          string/ft_strjoin.c \
          string/ft_strlcat.c \
          string/ft_strlen.c \
          string/ft_strmap.c \
          string/ft_strmapi.c \
          string/ft_strncat.c \
          string/ft_strncmp.c \
          string/ft_strncpy.c \
          string/ft_strnequ.c \
          string/ft_strnew.c \
          string/ft_strnstr.c \
          string/ft_strrchr.c \
          string/ft_strsplit.c \
          string/ft_strstr.c \
          string/ft_strsub.c \
          string/ft_strtrim.c \
          unclassed/ft_atoi.c \
          unclassed/ft_digitlen.c \
          unclassed/ft_itoa.c \
          unclassed/ft_tolower.c \
          unclassed/ft_toupper.c \
          unclassed/get_next_line.c

SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))

#OBJ BLOC
#Do nothing here
OBJ_PATH= obj/
OBJ_NAME= $(SRC_NAME:.c=.o)
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

#GCC BLOC
#GCC flag, you don't have to modify this (but you're free to go)
GCC= clang -Wall -Wextra -Werror

#INCLUDE BLOC
#Don't forget to include the other librarie that yo use
INC_LIB=
INC_PATH= .
INC= -I $(INC_LIB) -I $(INC_PATH)

#Once again, don't forget to includes library that you use !
LIB=

#FRAMEWORK BLOC
#Don't forget to add framework that you need !
FRAMEWORK= 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) has been created."

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)/{is,lst,memory,print,string,unclassed}
	$(GCC) -I $(INC_PATH) -o $@ -c $<

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_PATH)
	@echo "$(NAME) objects files are deleted."

fclean: clean
	@rm -rf $(NAME)
	@echo "$(NAME) are deleted."

re: fclean all

norme:
	@norminette $(INC_LIB)*.[ch]

.PHONY: clean fclean re norme
