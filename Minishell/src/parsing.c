/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:20:26 by lvodak            #+#    #+#             */
/*   Updated: 2024/04/16 16:56:51 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// dans le cas de quotes ouvertes il semblerait qu'il faudrait un readline
// pour chaque ligne d'input a la suite tant que la deuxieme quotes n'est pas
// mise, et chaque nv input est precedé d'un \n
t_input	*create_node(char *str, int type)
{
	t_input	*node;

	node = malloc(sizeof(t_input));
	if (!node)
		return (0);
	node->token = str;
	node->type = type;
	node->next = NULL;
	node->arg = NULL;
	return (node);
}

int	get_token_type(char *c)
{
	if (c[0] == '|')
		return (PIPE_TK);
	else if (c[0] == '<' && c[1] == '<')
		return (HEREDOC_TK);
	else if (c[0] == '<')
		return (READ_TK);
	else if (c[0] == '>' && c[1] == '>')
		return (APPEN_TK);
	else if (c[0] == '>')
		return (WRITE_TK);
	else if (c[0] == '$')
		return (ENV_VAR_TK);
	else
		return (WORD_TK);
}

char	*split_token(char *str, int	*start, char quote)
{
	int		len;

	len = 0;
	if (str[*start] == '<' || str[*start] == '>')
		while ((str[*start] == '<' || str[*start] == '<') && str[*start] == str[*start + 1] && ++len <= 2)
			*start += 1;
	else if (quote != '\'' && quote != '\"')
		while (str[*start] && is_not_sep(str[*start]) && ++len)
			*start += 1;
	else
		while (str[*start] && (str[*start] != quote || (quote == '\"'
				&& str[*start - 1] != '\\')) && ++len)
			*start += 1;
	return (ft_substr(str, *start - len, len));
}

// < arg(1) cmd arg
// << arg(1) cmd arg
// cmd arg <> file
// ... | cmd (|| ...) arg

// a: 1er est cmd si pas de redir
// b: si redir, le suivant est arg et celui apres est cmd
// si pipe > a ou b

int	split_cmd_redir(t_input **cmd, char *str, int start)
{
	t_arg_lst	*arg;
	t_arg_lst	*first;
	int			token;

	token = 0;
	arg = NULL;
	first = arg;
	while (str[start] && str[start] != '|')
	{
		arg = malloc(sizeof(t_arg_lst));
		if (!arg)
			return (0);
		if (token == 2)
			*cmd = create_node(split_token(str, &start, 0), WORD_TK);
		else
		{
			arg->type = get_token_type(&str[start]);
			arg->token = split_token(str, &start, str[start]);
			arg = arg->next;
		}
		token++;
	}
	(*cmd)->arg = first;
	return (1);
}

int split_cmd(t_input **cmd, char *str, int start)
{
	t_arg_lst	*arg;
	t_arg_lst	*first;
	int			token;

	token = 0;
	arg = NULL;
	first = arg;
	// printf("AAAAAAAAAA");
	while (str[start] && str[start] != '|' && start < (int)ft_strlen(str))
	{
		arg = malloc(sizeof(t_arg_lst));
		if (!arg)
			return (0);
		if (token == 0){
			*cmd = create_node(split_token(str, &start, 0), WORD_TK); printf("%s\n", (*cmd)->token);}
		else
		{
			arg->type = get_token_type(&str[start]);
			arg->token = split_token(str, &start, str[start]);
			printf("%s\n", arg->token);
			arg = arg->next;
		}
		while (str[start] && is_white_space(str[start]))
			start++;
		token++;
	}
	(*cmd)->arg = first;
	return (1);
}

t_input	*get_input_struct(char *str)
{
	t_input	*cmd;
	t_input	**start;
	int		i;

	i = -1;
	cmd = NULL;
	start = &cmd;
	while (str[++i])
	{
		if (i == 0 || str[i] == '|')
		{
			if (str[i] == '|')
			{
				cmd = create_node("|", PIPE_TK);
				i++;
			}
			else if (str[i] == '<')
				i = split_cmd_redir(&cmd, str, i);
			else
				i = split_cmd(&cmd, str, i);
		}
		if (cmd)
			cmd = cmd->next;
	}
	return (*start);
}

t_input	*parse(char *str)
{
	t_input	*input;

	if (!str || !closed_quotes(str))
		return (ft_putstr_fd("parse error\n !!! HAS TO BE CHANGED", 2), NULL);
	input = get_input_struct(str);
	return (input);
}
