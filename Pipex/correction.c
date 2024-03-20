/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:26:01 by Gfinet            #+#    #+#             */
/*   Updated: 2024/03/18 19:39:41 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
gcc -Wall -Wextra -Werror correction.c libftprintf.a -o correction 
./correction cat wc echo "cat -e" "wc -w" "wc -l" "wc -c" 
*/


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
	int		i;
	int		j;
	int		nb_proc;
	int		nb_cmd;
	pid_t	*proc; // proc[16];
	int		*status; 
	char	**arg;
	char	**cmds;// *cmds[] = {"cat", "ls",  "wc", "echo", NULL};

	nb_cmd = argc - 1;
	nb_proc = nb_cmd * nb_cmd + 1;

	cmds = malloc(sizeof(char *) * (nb_cmd + 3));
	cmds[0] = ft_strdup("correction.sh");
	cmds[nb_cmd + 1] = ft_strdup(ft_itoa(nb_cmd));
	cmds[nb_cmd + 2] = NULL;
	i = 1;
	while (i - 1< nb_cmd)
	{
		cmds[i] = ft_strdup(argv[i]);
		i ++;
	}
	proc = malloc(sizeof(pid_t) * nb_proc);
	status = malloc(sizeof(int) * nb_proc);

	arg = malloc(sizeof(char *) * 5);
	arg[0] = ft_strdup("./pipex");
	arg[1] = ft_strdup("infile");

	i = 1;
	while (i - 1< nb_cmd && cmds[i])
	{
		j = 1;
		arg[2] = ft_strdup(cmds[i]);
		while (j - 1 < nb_cmd && cmds[j])
		{
			arg[3] = ft_strdup(cmds[j]);
			arg[4] = ft_strdup("c");
			arg[4] = ft_stradd(arg[4], ft_itoa(nb_cmd * (i - 1) + (j - 1)));
			proc[nb_cmd*(i-1)+(j-1)] = launch_pipex(arg, envp);
			j++;
			free(arg[3]);
			free(arg[4]);
		}
		free(arg[2]);
		i++;
	}
	i = 0;
	
	while (i < nb_proc)
	{
		waitpid(proc[i], &status[i], 0);
		i++;
	}
	proc[nb_proc - 1] = fork();
	if (proc[nb_proc - 1] == 0)
		execve("correction.sh", cmds, 0);
		//execve("correction.sh",(char*[]){"correction.sh","cat ls wc echo", NULL}, 0);
	free(arg[0]);
	free(arg[1]);
	free(arg);
	free(proc);
	i = 0;
	while (i < nb_cmd + 3)
	{
		free(cmds[i]);
		i++;
	}
	free(cmds);
	free(status);
	return (0);
}
