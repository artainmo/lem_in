NAME = lem-in

SRC = lem_in.c \
			src/parsing.c \
			src/display.c \
			utils/handle_struct.c \
			utils/get_next_line/get_next_line.c \
			utils/get_next_line/get_next_line_utils.c
OBJ = $(SRC:.c=.o)

LIBFLAGS = -I . -L . -I ./utils/libft -L ./utils/libft -I ./utils/get_next_line -I ./utils/ft_printf -L ./utils/ft_printf
# -I Add the directory dir to the list of directories to be searched for header files
# -L Searches the library when linking

GCC = gcc -Wall -Wextra -Werror
RM = rm -rf

all: libft_all printf_all $(NAME)


$(NAME): $(OBJ)
	$(GCC) $(LIBFLAGS) -o $(NAME) $(OBJ) libft.a libftprintf.a

%.o: %.c
	$(GCC) -c -o $@ $?
# $@ represents the target being build, in this case %.o (object files)
# $? represents the names of all the prerequisites that are newer than the target, thus here c files with recent changes

clean: libft_fclean printf_fclean
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# In this last section we make other makefiles compile with the -C flag
# The -C flag makes you go to the appropriate path and do the asked command
libft_all:
	make -C ./utils/libft all
	cp ./utils/libft/libft.a libft.a
libft_clean:
	make -C ./utils/libft clean
libft_fclean:
	make -C ./utils/libft fclean
	$(RM) libft.a

printf_all:
	make -C ./utils/ft_printf all
	cp ./utils/ft_printf/libftprintf.a libftprintf.a
printf_fclean:
	make -C ./utils/ft_printf fclean
	$(RM) libftprintf.a

.PHONY: all clean fclean re
