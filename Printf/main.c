/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:01:02 by gfinet            #+#    #+#             */
/*   Updated: 2024/02/14 18:24:29 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#define PARAMS 

//"bonjour %s %c, vous avez le numéro %u%i avec 50%%\n", "hello", 'W', 5, -3
//"%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% 
// %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', 
// "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0
//"%c", 0
//"%p", char *p

int	main(void)
{
	printf("yours ==> %d\n", ft_printf(PARAMS));
	printf("classic ==> %d\n", printf(PARAMS));
	return (0);
}
