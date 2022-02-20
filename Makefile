CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf_bonus.c ft_print_%_bonus.c ft_print_c_bonus.c ft_print_s_bonus.c src/ft_strlen.c src/ft_strchr.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

all : $(NAME)

bonus : all

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re