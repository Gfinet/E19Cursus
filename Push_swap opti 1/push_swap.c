/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:21:32 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/16 18:39:05 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *s)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = (s[0] == '-');
	if (i && len == 1)
		return (0);
	while (i < len)
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int check_input(char **s, int n_arg)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = i + 1;
		while (j < n_arg && s[j])
		{
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (0);
			j++;
		}
		if (!is_number(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	fill_a(t_nlst **a, char **arg, int nb_arg)
{
	t_nlst  *p;
	int	 i;

	i = 0;
	while (i < nb_arg)
	{
		p = ft_nlstnew(ft_atoi(arg[i]));
		if (!p)
			ft_nlstclear(a, free);
		ft_nlstadd_back(a, p);
		i++;
	}
	return (1);
}


int push_swap(char **arg, int nb_arg)
{
	t_nlst  *a;
	t_nlst  *b;
	t_nlst	*p;

	a = NULL;
	b = NULL;
	if (!fill_a(&a, arg, nb_arg))
		return (0);
	p = a;
	while (p)
	{
		printf("a %i\n", p->content);
		p = p->next;
	}
	ps_sort(&a, &b);
	ft_printf("\n");
	p = a;
	while (p)
	{
		printf("b %i\n", p->content);
		p = p->next;
	}
	ft_nlstclear(&a, free);
	ft_nlstclear(&b, free);
	//ps_sort(&a, &b);
	return (1);
}


// int main(int argc, char **argv)
// {
//	 if (argc < 2)
//		 return (0);
//	 if (!check_input(&argv[1]))
//		 return (0);
//	 if (!push_swap(&argv[1]))
//		 return (0);
//	 return (0);
// }

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	printf("check input = %i\n", check_input(&argv[1], argc--));
	printf("push_swap = %i\n", push_swap(&argv[1], argc--));
	
	return (0);
}
