# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artainmo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 21:50:42 by artainmo          #+#    #+#              #
#    Updated: 2020/02/26 19:19:19 by artainmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC	= ft_memset.c \
        	ft_bzero.c \
        	ft_memcpy.c \
        	ft_memccpy.c \
        	ft_memmove.c \
        	ft_memchr.c \
        	ft_memcmp.c \
	        ft_strlen.c \
	        ft_isalpha.c \
	        ft_isdigit.c \
	        ft_isalnum.c \
	        ft_isascii.c \
	        ft_isprint.c \
	        ft_toupper.c \
	        ft_tolower.c \
	        ft_strchr.c \
	        ft_strrchr.c \
	        ft_strncmp.c \
	        ft_strlcpy.c \
	        ft_strlcat.c \
	        ft_strnstr.c \
	        ft_atoi.c \
	        ft_calloc.c \
	        ft_strdup.c \
	        ft_substr.c \
	        ft_strjoin.c \
	        ft_strtrim.c \
	        ft_itoa.c \
	        ft_strmapi.c \
	        ft_putchar_fd.c \
	        ft_putstr_fd.c \
	        ft_putendl_fd.c \
	        ft_putnbr_fd.c \
	        ft_split.c \
					ft_strcmp.c \
					ft_strrchr_m.c \
					ft_strjoin_f.c \
					ft_filetrim.c \
					ft_filerep.c \
					ft_filebordertrim.c \
					ft_error.c \
					ft_cut.c \
					ft_add_end_ds.c \
					ft_remove_begin_ds.c \
					ft_print_ds.c \
					ft_free_ds.c \
					ft_len_ds.c \
					ft_round.c \
					ft_dec_to_hex.c \
					ft_strrev.c
SBONUS = ft_lstnew_bonus.c \
	        ft_lstadd_front_bonus.c \
	        ft_lstsize_bonus.c \
	        ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c \
	        ft_lstdelone_bonus.c \
	        ft_lstclear_bonus.c \
	        ft_lstiter_bonus.c \
	        ft_lstmap_bonus.c
SRCSH	= libft.h
OBJS	= $(SRCSC:%.c=%.o)
OBONUS	= $(SBONUS:%.c=%.o)
NAME	= libft.a
CC	= gcc
AR	= ar rc
RM	= rm -f
CFLAGS = -Wall -Wextra -Werror

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS} ${OBONUS}

fclean:		clean
			${RM} ${NAME}

re:	fclean all

bonus:	all ${OBONUS}
			${AR} ${NAME} ${OBONUS}

.PHONY:	all clean fclean re
