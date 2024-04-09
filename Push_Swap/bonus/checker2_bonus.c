/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:12:38 by Gfinet            #+#    #+#             */
/*   Updated: 2024/04/09 09:13:41 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_input(char **s, int n_arg)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[i]) != ft_strlen(ft_itoa(ft_atoi(s[i]))))
			return (0);
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
