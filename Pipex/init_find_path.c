/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_find_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:44:34 by Gfinet            #+#    #+#             */
/*   Updated: 2024/02/14 17:43:33 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	split_cmd(t_cmds *c, char *infile, char *arg, int ind)
{
	char	*tmp;

	tmp = ft_strdup(arg);
	if (!tmp)
		return (0);
	else if (infile)
	{
		tmp = ft_stradd(tmp, " ");
		if (!tmp)
			return (0);
		tmp = ft_stradd(tmp, infile);
		if (!tmp)
			return (0);
	}
	c->arg[ind] = ft_split(tmp, ' ');
	if (!c->arg[ind])
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	init_t_cmds(t_cmds *c, int argc, char **envp)
{
	int	flag;

	flag = 1;
	while (*(envp) && flag)
		flag = ft_strncmp(*(envp++), "PATH", 4);
	if (flag)
		return (-10);
	c->path = ft_split(*(--envp), ':');
	if (!c->path)
		return (-5);
	c->nb_pr = argc - 3;
	c->arg = malloc(sizeof(char **) * c->nb_pr);
	if (!c->arg)
		return (-5);
	c->cmd_arg = malloc(sizeof(char *) * c->nb_pr);
	if (!c->cmd_arg)
		return (-5);
	return (1);
}

t_mall	*set_t_mall(char *p, int f)
{
	t_mall	*tmp;

	tmp = malloc(sizeof(t_mall));
	tmp->f = f;
	tmp->p = p;
	return (tmp);
}

t_mall	*find_path(t_cmds *c, char *arg, char *infile, int ind)
{
	t_mall	*cmd_arg;
	int		i;

	i = 0;
	cmd_arg = set_t_mall(0, 0);
	if (!split_cmd(c, infile, arg, ind) || !cmd_arg)
		return (0);
	cmd_arg->p = ft_strdup(arg);
	cmd_arg->f = (access(cmd_arg->p, F_OK) == 0);
	while (c->path[i++] && access(cmd_arg->p, F_OK) != 0)
	{
		free(cmd_arg->p);
		cmd_arg->p = ft_strjoin(c->path[i], "/");
		if (!cmd_arg)
			return (cmd_arg);
		cmd_arg->p = ft_stradd(cmd_arg->p, c->arg[ind][0]);
		if (!cmd_arg->p)
			return (cmd_arg);
		if (access(cmd_arg->p, F_OK) == 0 && access(cmd_arg->p, X_OK) == 0)
			cmd_arg->f = 1;
	}
	if (cmd_arg->f && !ft_strncmp(cmd_arg->p, "PATH", 4))
		cmd_arg->p = ft_strtrim(cmd_arg->p, "PATH=");
	return (cmd_arg);
}

int	find_all_path(t_cmds *c, char **argv, int nb_pr)
{
	int		i;
	int		flag;
	t_mall	*tmp;

	i = 0;
	flag = 1;
	while (i < nb_pr)
	{
		if (i == 0)
			tmp = find_path(c, argv[2], argv[1], i);
		else
			tmp = find_path(c, argv[i + 2], 0, i);
		if (!tmp)
			return (-5);
		if (!tmp->p && !tmp->f)
			return (-5);
		if (tmp->p && !tmp->f)
			flag = 0;
		c->cmd_arg[i] = tmp->p;
		free(tmp);
		i++;
	}
	if (!flag)
		return (-8);
	return (1);
}
