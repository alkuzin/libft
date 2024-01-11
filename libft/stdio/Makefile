CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

NAME = stdio.o

SRC = ft_putchar ft_puts ft_putstr ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd
PRINTF_SRC = ft_printf ft_printf_int ft_printf_str ft_printf_char ft_printf_uint ft_printf_hex
PRINTF_SRC_PREFIXED = $(addprefix printf/, $(PRINTF_SRC))

SRCS = $(addsuffix .c, $(SRC) $(PRINTF_SRC_PREFIXED))
OBJS = $(addsuffix .o, $(SRC) $(PRINTF_SRC_PREFIXED))
OBJECTS = $(addsuffix .o, $(SRC) $(PRINTF_SRC))

OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJECTS))

$(OBJS_PREFIXED): $(SRCS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(OBJS_DIR)

$(NAME): $(OBJS_PREFIXED)
	ld -relocatable $(OBJS_PREFIXED) -o $(NAME)

all: $(NAME) 

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: clean all
