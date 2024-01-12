#include <stdio.h>
#include <stdint.h>

char hex_digit(int v) {
   if (v >= 0 && v < 10)
       return '0' + v;
   else
       return 'a' + v - 10;
}

void print_address_hex(void* p0) {
   int i;
   uintptr_t p = (uintptr_t)p0;

   putchar('0'); 
   putchar('x');
   for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
       putchar(hex_digit((p >> i) & 0xf));
   }
}

int main()
{
	int c = 126;
	void *p = &c;

	print_address_hex(p);

	printf("\npointer: %p\n", p);
	return 0;
}
