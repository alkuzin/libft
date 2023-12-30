CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

NAME = libft.a

FT_STDIO_PATH=stdio/
FT_CTYPE_PATH=ctype/
FT_MEMORY_PATH=memory/
FT_STRING_PATH=string/
FT_STDLIB_PATH=stdlib/
FT_MATH_PATH=math/

FINAL_OBJS = $(FT_STDIO_PATH)stdio.o   \
			 $(FT_CTYPE_PATH)ctype.o   \
			 $(FT_MEMORY_PATH)memory.o \
			 $(FT_STRING_PATH)string.o \
			 $(FT_STDLIB_PATH)stdlib.o \
			 $(FT_MATH_PATH)math.o \

$(FINAL_OBJS):
	$(MAKE) -C $(FT_STDIO_PATH)  all
	$(MAKE) -C $(FT_CTYPE_PATH)  all
	$(MAKE) -C $(FT_MEMORY_PATH) all
	$(MAKE) -C $(FT_STRING_PATH) all
	$(MAKE) -C $(FT_STDLIB_PATH) all
	$(MAKE) -C $(FT_MATH_PATH)   all

all: $(NAME) 

$(NAME): $(FINAL_OBJS)
	ar rcs $(NAME) $(FINAL_OBJS)

clean:
	$(MAKE) -C $(FT_STDIO_PATH)  fclean
	$(MAKE) -C $(FT_CTYPE_PATH)  fclean
	$(MAKE) -C $(FT_MEMORY_PATH) fclean
	$(MAKE) -C $(FT_STRING_PATH) fclean
	$(MAKE) -C $(FT_STDLIB_PATH) fclean
	$(MAKE) -C $(FT_MATH_PATH)   fclean

fclean: clean
	rm -f $(NAME)

re: clean all
