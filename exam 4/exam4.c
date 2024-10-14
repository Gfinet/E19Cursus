/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:49:45 by gfinet            #+#    #+#             */
/*   Updated: 2024/10/14 21:37:46 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct s_cmd
{
	char	**buff;
	char	*sep;
	int		pipe[2];
	int		cur;
	int		nb_cmd;
	pid_t	*proc;
}	t_cmd;

char **cut_cmd(int *i, char **av)
{
	int j, k;
	char **buf;

	j = 0;
	while (av[(*i) + j] && strcmp(av[(*i) + j], "|") && strcmp(av[(*i) + j], ";"))
		j++;
	buf = malloc(sizeof(char *) * (j + 1));
	buf[j] = 0;
	k = 0;
	while (k < j)
	{
		buf[k] = av[(*i) + k];
		k++;
	}
	*i+=j;
	return (buf);
}

int count_proc(char **av, char **sep)
{
	int nb = 1, i = -1, j = 0;

	while (av[++i])
		nb += !strcmp(av[i], "|") + !strcmp(av[i], ";");
	*sep = malloc(sizeof(char) * (nb));
	(*sep)[nb - 1] = 0;
	i = -1;
	while (av[++i])
	{
		if ((!strcmp(av[i], "|") || !strcmp(av[i], ";")) && j < nb - 1)
			(*sep)[j++] = av[i][0];
	}
	return (nb);
}

int back_dup(t_cmd *cmd)
{
	printf("backdup\n");
	if (dup2(cmd->pipe[0], STDIN_FILENO) == -1)
		return (0);
	return (1);
}

int next_dup(t_cmd *cmd)
{
	printf("nextdup\n");
	if (dup2(cmd->pipe[1], STDOUT_FILENO) == -1)
		return (0);
	return (1);
}

void launch_cmd(t_cmd *cmd, char **envp, int pip)
{
	printf("pip %d\n", pip);
	if (cmd->cur > 1)
		printf("cur %d\n", cmd->cur);
	if (pip && cmd->nb_cmd > 1 && cmd->cur > 0 && cmd->sep[cmd->cur - 1] == '|'
		&& back_dup(cmd))
		exit(EXIT_FAILURE);
	if (pip && cmd->cur < cmd->nb_cmd - 1 && cmd->sep[cmd->cur] == '|'
		&& next_dup(cmd))
		exit(EXIT_FAILURE);
	if (cmd->pipe[0] > 2)
		close(cmd->pipe[0]);
	if (cmd->pipe[1] > 2)
		close(cmd->pipe[1]);
	execve(cmd->buff[0], cmd->buff, envp);
	exit(EXIT_FAILURE);
}

int main(int ac, char **av, char **env)
{
	t_cmd cmd;
	int i, k, inf, pip[2];

	i = 0;
	cmd = (t_cmd){0};
	if (ac < 2)
		return (1);
	cmd.nb_cmd = count_proc(av, &cmd.sep);
	printf("nb : %d\nsep : [%s]\n", cmd.nb_cmd, cmd.sep);
	cmd.proc = malloc(sizeof(pid_t) * (cmd.nb_cmd + 1));
	while (i++ < ac)
	{
		cmd.buff = cut_cmd(&i, av);
		if (!cmd.buff)
			return (write(2, "error: fatal\n", 13), 1);
		
		// k = 0;
		// while (cmd.buff[k])
		// 	printf("%s ", cmd.buff[k++]);
		// printf("\n");
		pip[0] = (cmd.nb_cmd > 1 && cmd.sep[cmd.cur] == '|');
		pip[1] = (cmd.cur && cmd.cur < cmd.nb_cmd && cmd.sep[cmd.cur - 1] == '|');
		printf("\nsssep %c\n", cmd.sep[cmd.cur]);
		if ((cmd.nb_cmd > 1 && cmd.sep[cmd.cur] == '|') && printf("PIPE\n") && pipe(cmd.pipe) < 0)
				return (write(2, "error: fatal\n", 13), 1);

		cmd.proc[cmd.cur] = fork();
		if (cmd.proc[cmd.cur] == 0)
			launch_cmd(&cmd, env, pip[0] || pip[1]);
		inf = cmd.pipe[0];
		if (cmd.pipe[0] > 2)
			close(cmd.pipe[0]);
		cmd.pipe[0] = inf;
		if (cmd.pipe[1] > 2)
			close(cmd.pipe[1]);
			printf("pipe %d %d\n", cmd.pipe[0], cmd.pipe[1]);
		free(cmd.buff);
		cmd.cur++;
	}
	cmd.cur = -1;
	while (++cmd.cur < cmd.nb_cmd)
		waitpid(cmd.proc[cmd.cur], 0, 0);
	k = 0;
	free(cmd.proc);
	free(cmd.sep);
	return (0);
}