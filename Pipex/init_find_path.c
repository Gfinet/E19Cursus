/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_find_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:44:34 by Gfinet            #+#    #+#             */
/*   Updated: 2024/02/07 17:44:39 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	split_cmd(char ***command, char *infile, char *arg)
{
	char	*tmp;

	tmp = ft_strdup(arg);
	if (!tmp)
		return (0);
	if (infile)
	{
		tmp = ft_stradd(tmp, " ");
		if (!tmp)
			return (0);
		tmp = ft_stradd(tmp, infile);
		if (!tmp)
			return (0);
	}
	(*command) = ft_split(tmp, ' ');
	if (!*command)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	init_t_cmds(t_cmds *c, int argc, char **envp)
{
	while (*(envp) && ft_strncmp(*(++envp), "PATH", 4))
		;
	c->path = ft_split(*(envp), ':');
	if (!c->path)
		return (-5);
	c->nb_pr = argc - 3;
	ft_printf("c.path %s\n", c->path[0]);
	c->arg = malloc(sizeof(char **) * c->nb_pr);
	if (!c->arg)
		return (-5);
	c->cmd_arg = malloc(sizeof(char *) * c->nb_pr);
	if (!c->cmd_arg)
		return (-5);
	return (1);
}

char	*find_path(char ***command, char **path, char *arg, char *infile)
{
	char	*cmd_arg;
	int		i;

	i = 0;
	if (!split_cmd(command, infile, arg))
		return (0);
	while (path[i])
	{
		cmd_arg = ft_strjoin(path[i], "/");
		if (!cmd_arg)
			return (0);
		cmd_arg = ft_stradd(cmd_arg, (*command)[0]);
		if (!cmd_arg)
			return (0);
		if (access(cmd_arg, F_OK) == 0)
			break ;
		free(cmd_arg);
		i++;
	}
	return (cmd_arg);
}

int	find_all_path(t_cmds *c, char **argv, int nb_pr)
{
	int		i;
	char	*p;

	i = 0;
	while (i < nb_pr)
	{
		if (i == 0)
			p = find_path(&(c->arg[0]), c->path, argv[2], argv[1]);
		else
			p = find_path(&(c->arg[i]), c->path, argv[i + 2], 0);
		if (!p)
			return (free_all_pipex(c, 0));
		c->cmd_arg[i] = p;
		i++;
	}
	return (1);
}
