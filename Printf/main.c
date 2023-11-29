#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	char *s = NULL;
	printf("%d --> ", printf("%c %d %i %x %X %p %s %%\n", 2000, 3, 0, 255, 255, NULL, NULL));
	printf("%d --> ", ft_printf("%c %d %i %x %X %p %s %%\n", 2000, 3, 0, 255, 255, NULL, NULL));
}