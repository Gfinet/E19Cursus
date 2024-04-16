/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:40:23 by lvodak            #+#    #+#             */
/*   Updated: 2024/04/07 21:43:00 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int is_white_space(char c)
{
	return (((c >= 9 && c <= 13) || c == 32));
}

int	is_not_sep(char c)
{
	return (!(is_white_space(c) || c == 34 || c == 36 || c == 39 || c == 45
				|| c == 60 || c == 62 || c == 124));
}

int	closed_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\'')
		{
			while (str[i] && str[i] != '\'')
				if (!str[++i])
					return (0);
		}
		if (str[i] == '\"')
		{
			while (str[i] && str[i] != '\"')
				if (!str[++i])
					return (0);
		}
	}
	return (1);
}
// si une commande d'un pipe est inccorrecte les autres peuvent s'executer; si une pipe est suivi d'une autre sans espace
// seule les commande precedentes seront execute; si un espace se trouve entre deux pipe, rien ne fonctionne(?) mais le fichier
// devrait se creer normalement (?);
int	check_for_pipe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (str[i++] == '|') // checker si pipe est entre des quotes, car est char si entre '"
			break ;
	if (!str[i])
		return (0);
	return (1);
}
