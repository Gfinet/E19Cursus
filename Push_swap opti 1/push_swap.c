/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:21:32 by gfinet            #+#    #+#             */
/*   Updated: 2023/12/29 06:35:11 by Gfinet           ###   ########.fr       */
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

static int	fill_a(t_nlst_head *a, char **arg, int nb_arg)
{
	t_nlst  *p;
	int	 i;

	i = 0;
	while (i < nb_arg)
	{
		p = ft_nlstnew(ft_atoi(arg[i]));
		if (!p)
			return (ft_nlstclear(a, free));
		ft_nlstadd_back(a, p);
		i++;
	}
	return (1);
}


t_res *push_swap(char **arg, int nb_arg)
{
	t_nlst_head  	*a;
	t_nlst_head  	*b;
	t_nlst			*p;
	t_res 			*res;

	nlst_head_init(&a);
	nlst_head_init(&b);
	res_init(&res);
		
	if (!fill_a(a, arg, nb_arg))
		return (res);
	a->lower = nlst_get_low_big(a, 0);
	a->bigger = nlst_get_low_big(a,1);
	a->median = nlst_get_median(a, ft_nlstsize(a));
	// p = a;
	// while (p)
	// {
	// 	ft_printf("%i\n", p->content);
	// 	p = p->next;
	// }
	p = a->first;
	while (p)
	{
		ft_printf("%i ", p->content);
		p = p->next;
	}
	ft_printf("\nmedian = %d\n", nlst_get_median(a, ft_nlstsize(a)));
	ps_sort(a, b);
	ft_printf("\n");
	p = a->first;
	while (p)
	{
		ft_printf("%i ", p->content);
		p = p->next;
	}
	res->moves = nlst_compute_moves(a);
	res->sorted = check_heap(&a->first, 0);
	ft_nlstclear(a, free);
	ft_nlstclear(b, free);
	//ps_sort(&a, &b);
	return (res);
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
	t_res	*res;
	if (argc < 2)
		return (0);
	res = malloc(sizeof(t_res));
	res = push_swap(&argv[1], argc - 1);
	ft_printf("check input = %i\n", check_input(&argv[1], argc--));
	ft_printf("push_swap = %i\n", res->sorted);
	ft_printf("moves = %i\n", res->moves);
	free(res);
	
	return (0);
}
