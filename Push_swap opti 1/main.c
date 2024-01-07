/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 00:59:08 by Gfinet            #+#    #+#             */
/*   Updated: 2024/01/07 02:02:31 by Gfinet           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_res	*res;
	int		nb_elem;
	char	**nums;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		nums = ft_split(argv[1], '\n');
		nb_elem = 0;
		while (nums[nb_elem])
			nb_elem++;
		res = push_swap(nums, nb_elem);
		ft_printf("check input = %i\n", check_input(nums, nb_elem));
	}
	else
	{
		res = push_swap(&argv[1], argc - 1);
		ft_printf("check input = %i\n", check_input(&argv[1], argc - 1));
	}
	
	ft_printf("push_swap = %i\n", res->sorted);
	ft_printf("moves = %i\n", res->moves);
	free(res);
	return (0);
}
