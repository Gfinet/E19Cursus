/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:09:38 by lvodak            #+#    #+#             */
/*   Updated: 2024/04/16 15:17:29 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include <time.h>
// #include <termios.h>

void	print_input_lst(t_input	*input)
{
	while (input)
	{
		printf("%scmd%s = %s\n", RED, NC, input->token);
		if (input->arg)
		{
			while (input->arg)
			{
				printf("\t%sarg%s = %s\n", LBLUE, NC, input->arg->token);
				input->arg = input->arg->next;
			}
		}
		input = input->next;
	}
}

int main()
{
	char 	*str;
	t_input	*input;

	str = NULL;
	while (1)
	{
		printf("%sMinishell %s\t%s", GREEN, getcwd(NULL, 0), NC);
		str = readline(NULL);
		input = parse(str);
		print_input_lst(input);
	}
}