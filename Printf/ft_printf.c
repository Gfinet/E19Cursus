/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:24:02 by gfinet            #+#    #+#             */
/*   Updated: 2023/11/04 20:56:54 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	count_percent(const char *arg0)
{
	int		nb;
	int		i;
	size_t	len;

	nb = 0;
	i = 0;
	len = ft_strlen(arg0);
	while (arg0[i])
	{
		if (arg0[i] == '%' && (arg0[i + 1]))
		{
			nb++;
			i++;
		}
		else if (!(arg0[i + 1]) && arg0[i] == '%')
		{
			ft_putendl_fd("probleme \% en fin de str", 1);
			return (-1);
		}
		i++;
	}
	return (nb);
}

static int	check_conv(char c)
{
	if (c == '%')
		return (1);
	else if (c == 'c')
		return (2);
	else if (c == 's')
		return (3);
	else if (c == 'p')
		return (4);
	else if (c == 'd' || c == 'i')
		return (5);
	else if (c == 'u')
		return (6);
	else if (c == 'x')
		return (7);
	else if (c == 'X')
		return (8);
	return (0);
}

char	*string_test(char *s)
{
	if (s)
		return (ft_strdup(s));
	else
		return (ft_strdup("(null)"));
}

char	*modif_current(const char *arg0, char *current, va_list ap)
{
	char	tmp[2];

	tmp[1] = '\0';
	if (check_conv(*(arg0)) == 1)
		current = ft_strdup("%\0");
	else if (check_conv(*(arg0)) == 2)
	{
		tmp[0] = va_arg(ap, int);
		current = ft_strndup(tmp, 2);
	}
	else if (check_conv(*(arg0)) == 3)
		current = string_test(va_arg(ap, char *));
	else if (check_conv(*(arg0)) == 4)
		current = ft_ltoa_base(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (check_conv(*(arg0)) == 5)
		current = ft_ltoa_base(va_arg(ap, int), "0123456789");
	else if (check_conv(*(arg0)) == 6)
		current = ft_ltoa_base(va_arg(ap, unsigned int), "0123456789");
	else if (check_conv(*(arg0)) == 7)
		current = ft_ltoa_base(va_arg(ap, long), "0123456789abcdef");
	else if (check_conv(*(arg0)) == 8)
		current = ft_ltoa_base(va_arg(ap, long), "0123456789ABCDEF");
	return (current);
}

static int	compute_lenl(char const *s)
{
	int		nb;
	int		i;
	int		flag;

	nb = 0;
	i = -1;
	flag = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			flag = 0;
			if (check_conv(s[i + 1]) && s[i + 1])
				i++;
			else
				return (-1);
			nb++;
		}
		else if (!flag)
		{
			flag = 1;
			nb++;
		}
	}
	return (nb);
}

static int	free_all(char **final, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(final[i]);
		i++;
	}
	free(final);
	return (0);
}

static int	make_list(char **final, char **args, char *arg0, int nb_arg)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	while (*arg0 != '\0')
	{
		j = 0;
		while (arg0[j] != '%' && arg0[j])
			j++;
		if (j)
		{
			final[++k] = ft_strndup(arg0, j);
			if (!final[k])
				return (free_all(final, k));
		}
		if (i < nb_arg)
		{
			final[++k] = ft_strdup(args[i]);
			if (!final[k])
				return (free_all(final, k));
			i++;
		}
		arg0 += j + 2 * (arg0[j] != '\0');
	}
	return (1);
}

int	make_args(char **args, const char *arg0, int nb_arg, va_list ap)
{
	int		i;
	char	*current;

	if (!nb_arg)
		return (1);
	i = 0;
	while (i < nb_arg)
	{
		while (*arg0 != '%' && *arg0)
			arg0++;
		current = modif_current(++arg0, current, ap);
		if (!current)
			return (free_all(args, i));
		if (*arg0 == 'p')
			args[i] = ft_strjoin("Ox", current);
		else
			args[i] = ft_strdup(current);
		free(current);
		if (!args[i])
			return (free_all(args, i));
		i++;
	}
	return (1);
}

int	ft_finish(char **final, char **args, const char *arg0, int nb_arg)
{
	int		tt_len;
	int		i;
	int		size;

	i = 0;
	size = compute_lenl(arg0);
	tt_len = 0;
	while (i < size)
	{
		ft_putstr_fd(final[i], 1);
		tt_len += ft_strlen(final[i]);
		i++;
	}
	free_all(args, nb_arg);
	free_all(final, compute_lenl(arg0));
	return (tt_len);
}

int	ft_make_total(const char *arg0, int nb_arg, va_list cpy)
{
	char	**final;
	char	**args;

	args = malloc((nb_arg + 1) * sizeof(char *));
	if (!args)
		return (-1);
	if (!make_args(args, arg0, nb_arg, cpy))
		return (-1);
	final = malloc((compute_lenl(arg0) + 1) * sizeof(char *));
	if (!final)
		return (-1);
	if (!make_list(final, args, (char *)arg0, nb_arg))
		return (-1);
	return (ft_finish(final, args, arg0, nb_arg));
}

int	ft_printf(const char *arg0, ...)
{
	va_list	ap;
	va_list	cpy;
	int		nb_arg;
	int		res;

	if (!arg0)
		return (0);
	nb_arg = count_percent(arg0);
	if (nb_arg)
	{
		va_start(ap, arg0);
		va_copy(cpy, ap);
		va_start(cpy, arg0);
		res = ft_make_total(arg0, nb_arg, cpy);
		va_end(cpy);
		va_end(ap);
		return (res);
	}
	else if (!nb_arg)
		ft_putstr_fd((char *)arg0, 1);
	else
		return (-1);
	return (ft_strlen(arg0));
}

// int main()
// {
// 	// char c = 'W';
// 	// char *s = "Hello";
// 	// unsigned int 	u = 5;
// 	// int i = -3;
// // 	// printf("percent (9) = %d\n", count_percent("%cbouh%shex%pft%dffff%ipout%uhey%xdshjfb%Xfds%%"));
// // 	// printf("lenl (17) = %d\n", compute_lenl("%cbouh%shex%pft%dffff%ipout%uhey%xdshjfb%Xfds%%"));
// // 	// printf("percent (9) = %d\n", count_percent("%c    %s . %p .  %d .  %i . %u . %x %X %% "));
// // 	// printf("lenl (18) = %d\n", compute_lenl("%c    %s . %p .  %d .  %i . %u . %x %X %% "));
// // 	// printf("percent (0) = %d\n", count_percent(" "));

// // printf("1 %d vs %d\n", ft_printf("bonjour %s %c, vous avez le numéro %u%i avec 50%%\n", s, c, u, i), printf("bonjour %s %c, vous avez le numéro %u%i avec 50%%\n", s, c, u, i));
// // printf("2 %d vs %d\n", ft_printf("bonjour\n"), printf("bonjour\n"));
// // printf("3 %d vs %d\n", ft_printf("bonjour %s %i %c teub\n", s, i, c), printf("bonjour %s %i %c teub\n", s, i, c));
// // printf("4 %d vs %d\n", ft_printf("bonjour %c\n", c), printf("bonjour %c\n", c));
// // printf("5 %d vs %d\n", ft_printf("bonjour %p\n", s), printf("bonjour %p\n", s));
// // printf("6 %d vs %d\n", ft_printf("bonjour numéro %u\n", u), printf("bonjour numéro %u\n", u));
// // printf("7 %d vs %d\n", ft_printf("bonjour %x\n", 160), printf("bonjour %x\n", 160));
// // printf("8 %d vs %d\n", ft_printf("bonjour %X\n", 160), printf("bonjour %X\n", 160));
// // printf("9 %d vs %d\n", ft_printf("bonjour, vous avez 50%%\n"), printf("bonjour, vous avez 50%%\n"));

	// ft_printf("%s", NULL);
// 	ft_printf(" %c %c %c ", '0', 0, '1');

// 	// cspdiuxX%
// 	return (0);
// }
//%c    %s . %p .  %d .  %i . %u . %x %X %% . 
/*
%c char.
%s *char.
%p pointeur void * en hexadécimal.
%d décimal (base 10).
%i int.
%u unsigned int.
%x hexadécimal minuscules.
%X hexadécimal majuscules.
%% pourcentage.
*/