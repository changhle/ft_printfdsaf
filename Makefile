CC = clang
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
SRCS = ft_printf.c print_percent.c print_c.c print_s.c print_diu.c print_pxX.c ft_strlen.c ft_strchr.c
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
