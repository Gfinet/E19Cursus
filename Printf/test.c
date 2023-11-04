#include <stdio.h>
#include "libftprintf.h"


int main ()
{
	char 			*s = "Monsieur";
	char			c = 'W';
	unsigned int 	u = 5;
	int				i = -5; 

	printf ("bonjour\n");
	ft_printf ("bonjour\n");
	printf ("bonjour %c\n", c);
	ft_printf ("bonjour %c\n", c);
	printf ("bonjour %s\n", s);
	ft_printf ("bonjour %s\n", s);
	printf ("bonjour %p\n", s);
	ft_printf ("bonjour %p\n", s);
	printf ("bonjour numéro %u\n", u);
	ft_printf ("bonjour numéro %u\n", u);
	printf ("bonjour numéro %i\n", i);
	ft_printf ("bonjour numéro %i\n", i);
	printf ("bonjour %x\n", 16);
	ft_printf ("bonjour %x\n", 16);
	printf ("bonjour %X\n", 16);
	ft_printf ("bonjour %X\n", 16);
	printf ("bonjour, vous avez 50%%\n");
	ft_printf ("bonjour, vous avez 50%%\n");
	//printf ("bonjour, vous avez 50%% %\n");
	printf ("bonjour %s %c, vous avez le numéro %u%i avec 50%%\n", s, c, u, i);
	ft_printf ("bonjour %s %c, vous avez le numéro %u%i avec 50%%\n", s, c, u, i);


	return (0);
}
/*
%c char.
%s *char.
%p pointeur void * en hexadécimal.
%d décimal (base 10).
%i int.
%u unsigned int.
%x hexadécimal minuscules.
%X hexadécimal majuscules.
%% pourcentage.*/