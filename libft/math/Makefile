CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

NAME = math.o

SRC = ft_exp ft_permutations ft_factorial ft_pfactorial ft_log ft_pow ft_sqrt ft_variations ft_variations_r ft_combinations ft_combinations_r ft_inf

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

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
