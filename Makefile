.PHONY: all clean fclean re

NAME 	= libftprintf.a

CC 		= gcc

FLAGS	= -Wall -Wextra -Werror


SRC 	 =  ft_printf.c  ft_put_ptr.c ft_putchar.c 		\
			ft_puthex.c  ft_putnbr.c  ft_putstr.c  ft_put_unsigned.c


OBJS = $(SRC:%.c=%.o)
	
all: $(NAME)

$(OBJS): $(SRC)
	 $(CC) $(FLAGS) -c $(SRC) 

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS) 

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all