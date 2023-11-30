CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wno-implicit-function-declaration

OBJS = ft_exp.o             \
		ft_factorial.o      \
		ft_pfactorial.o      \
		ft_log.o            \
	    ft_pow.o            \
	    ft_sqrt.o           \
	    ft_variations.o     \
		ft_variations_r.o 

FINAL_OBJ = math.o

final: $(OBJS)
	ld -relocatable $(OBJS) -o $(FINAL_OBJ)
	$(MAKE) clean

ft_exp.o: ft_exp.c
	$(CC) $(CFLAGS) -c ft_exp.c

ft_factorial.o: ft_factorial.c
	$(CC) $(CFLAGS) -c ft_factorial.c

ft_pfactorial.o: ft_pfactorial.c
	$(CC) $(CFLAGS) -c ft_pfactorial.c

ft_log.o: ft_log.c
	$(CC) $(CFLAGS) -c ft_log.c

ft_permutations.o: ft_permutations.c
	$(CC) $(CFLAGS) -c ft_permutations.c

ft_pow.o: ft_pow.c
	$(CC) $(CFLAGS) -c ft_pow.c

ft_sqrt.o: ft_sqrt.c
	$(CC) $(CFLAGS) -c ft_sqrt.c

ft_variations.o: ft_variations.c
	$(CC) $(CFLAGS) -c ft_variations.c

ft_variations_r.o: ft_variations_r.c
	$(CC) $(CFLAGS) -c ft_variations_r.c

clean:
	@echo "(*) Removing extra files"
	rm $(OBJS)