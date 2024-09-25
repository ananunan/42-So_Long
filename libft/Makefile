# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aeberius <aeberius@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:52:29 by aeberius          #+#    #+#              #
#    Updated: 2024/05/03 18:35:11 by aeberius         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

C.FILES=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_toupper.c ft_tolower.c ft_atoi.c \
	ft_bzero.c ft_strchr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_memcpy.c \
	ft_strlcpy.c ft_memchr.c ft_strnstr.c ft_memmove.c ft_strlcat.c \
	ft_strdup.c ft_calloc.c ft_substr.c ft_strtrim.c ft_strjoin.c \
	ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c ft_printf.c \
	ft_printchar.c ft_printstring.c ft_printdigits.c ft_printunsigned.c \
	ft_printpointer.c ft_putchar.c ft_printhex.c get_next_line.c get_next_line_utils.c

C.FILES_BONUS=ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJECTS=$(C.FILES:.c=.o)
OBJECTS_BONUS=$(C.FILES_BONUS:.c=.o)

CC=cc

FLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(C.FILES)
	$(CC) $(FLAGS) -c $(C.FILES)

bonus:
	$(CC) $(FLAGS) -c $(C.FILES_BONUS)
	ar rcs $(NAME) $(OBJECTS_BONUS)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(OBJECTS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
