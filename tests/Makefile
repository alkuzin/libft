CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

NAME = libfttest

LIBFT = libft.a
SRC = main libfttest

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

OBJS_DIR = objs/
LIBFT_PATH = ../libft/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

$(OBJS_PREFIXED): $(SRCS)
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $(SRCS)
	mv *.o $(OBJS_DIR)

$(NAME): $(OBJS_PREFIXED)
	$(MAKE) re -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJS_PREFIXED) $(LIBFT_PATH)$(LIBFT) -lm -o $(NAME)

all: $(NAME) 

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: clean all
