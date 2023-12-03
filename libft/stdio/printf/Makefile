CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

NAME = libftprintf.a

SRC = ft_printf ft_printf_int ft_printf_str ft_printf_itoa ft_printf_char

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

OBJ_DIR = obj

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME) 

clean:
	rm *.o

fclean: clean
	rm $(NAME)

re: clean all
