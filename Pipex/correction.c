/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:26:01 by Gfinet            #+#    #+#             */
/*   Updated: 2024/02/13 17:59:14 by Gfinet           ###   ########.fr       */
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
		_exit(EXIT_FAILURE);
	}
	return (proc);
}

int main(int argc, char **argv, char **envp)
{
	//char *newenviron[] = { NULL };
	int i;
	int j;
	pid_t proc[16];
	int status[5];
	char **arg;
	char *cmds[] = {"cat", "ls",  "wc", "echo", NULL}; //,"grep", "awk"

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

	// proc[0] = fork();
	// if (proc[0] == 0)
	// {
	// 	ft_printf("-----./pipex infile cat cat > c1-----\n");
	// 	execve("./pipex", (char *[]){"./pipex", "infile", "cat", "cat", "c1"}, envp);
	// 	_exit(EXIT_FAILURE);
	// }
	// proc[1] = fork();
	// if (proc[1] == 0)
	// {
	// 	ft_printf("-----./pipex infile cat ls > c2-----\n");
	// 	execve("pipex", (char *[]){"./pipex", "infile", "cat", "ls", "c2"}, envp);
	// 	_exit(EXIT_FAILURE);
	// }
	// proc[2] = fork();
	// if (proc[2] == 0)
	// {
	// 	ft_printf("-----./pipex infile ls cat > c3-----\n");
	// 	execve("pipex", (char *[]){"./pipex", "infile", "ls", "cat", "c3"}, envp);
	// 	_exit(EXIT_FAILURE);
	// }
	// proc[3] = fork();
	// if (proc[3] == 0)
	// {
	// 	ft_printf("-----./pipex infile ls ls > c4-----\n");
	// 	execve("pipex", (char *[]){"./pipex", "infile", "ls", "ls", "c4"}, envp);
	// 	_exit(EXIT_FAILURE);
	// }
	// execve("./pipex", (char *[]){"./pipex", "infile", "cat", "cat", "c1"}, envp);
	// execve("./pipex", (char *[]){"./pipex", "infile", "cat", "cat", "c1"}, envp);
	// execve("./pipex", (char *[]){"./pipex", "infile", "cat", "cat", "c1"}, envp);
	
	// waitpid(proc[0], &status[0], 0);
	// waitpid(proc[1], &status[1], 0);
	// waitpid(proc[2], &status[2], 0);
	waitpid(proc[15], &status[3], 0);
	proc[4] = fork();
	if (proc[4] == 0)
		execve("correction.sh",(char*[]){"correction.sh","cat ls wc echo", NULL}, 0);
	free(arg[0]);
	free(arg[1]);
	free(arg);

	return (0);
}