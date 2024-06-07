/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:23:43 by gfinet            #+#    #+#             */
/*   Updated: 2024/06/07 12:44:27 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	int i = 0, j;
	char c;

	(void)argc;

	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			c = argv[i][j];
			if (isalpha(c))
				c = toupper(c);
			std::cout << c;
			j++;
		}
	}

	return 0;
}