/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:26:01 by Gfinet            #+#    #+#             */
/*   Updated: 2024/02/14 18:30:27 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static pid_t launch_pipex(char **arg, char **envp)
{
	pid_t proc;

	proc = fork();
	if (proc == 0)
	{
		ft_printf("-----./pipex infile %s ", arg[2]); 
		ft_printf("%s > ", arg[3]);
		ft_printf("%s-----\n", arg[4]);
		execve(arg[0], arg, envp);
		exit(EXIT_FAILURE);
	}
	return (proc);
}

int main(int argc, char **argv, char **envp)
{
	int i;
	int j;
	pid_t proc[16];
	int status[5];
	char **arg;
	char *cmds[] = {"cat", "ls",  "wc", "echo", NULL};

	arg = malloc(sizeof(char *)*5);
	arg[0] = ft_strdup("./pipex");
	arg[1] = ft_strdup("infile");

	i = 0;
	while (cmds[i])
	{
		j = 0;
		arg[2] = ft_strdup(cmds[i]);
		while (cmds[j])
		{
			arg[3] = ft_strdup(cmds[j]);
			arg[4] = ft_strdup("c");
			arg[4] = ft_stradd(arg[4], ft_itoa(4* i + j));
			proc[4*i+j] = launch_pipex(arg, envp);
			j++;
			free(arg[3]);
			free(arg[4]);
		}
		free(arg[2]);
		i++;
	}
	waitpid(proc[15], &status[3], 0);
	proc[4] = fork();
	if (proc[4] == 0)
		execve("correction.sh",(char*[]){"correction.sh","cat ls wc echo", NULL}, 0);
	free(arg[0]);
	free(arg[1]);
	free(arg);

	return (0);
}