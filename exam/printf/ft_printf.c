/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:46:17 by Gfinet            #+#    #+#             */
/*   Updated: 2024/01/25 16:51:47 by Gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check_case(char p)
{
	if (p == 'd' || p == 'i')
		return (1);
	if (p == 'c')
		return (2);
	if (p == 's')
		return (3);
	if (p == 'p')
		return (4);
	if (p == 'x')
		return (5);
	if (p == 'X')
		return (6);
	if (p == 'u')
		return (7);
	if (p == '%')
		return (8);
	return (0);
}

int	count_percent(const char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && check_case(str[i + 1]))
			count++;
		else if (str[i] == '%' && !check_case(str[i + 1]))
			return (-1);
		i++;
	}
	return (count);
}

int ft_printf(const char *str, ...)
{
	va_list	app;

	if 

}

int main(void)
{
	ft_printf()
}