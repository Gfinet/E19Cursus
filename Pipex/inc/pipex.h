/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:22:48 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/02 00:21:00 by gfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 64
# endif
# include "../Printf/ft_printf.h"
// # define OPEN_ERROR -1
// # define READ_ERROR -2
// # define WRITE_ERROR -3
// # define FORK_ERROR -4
// # define MALLOC_ERROR -5
// # define PIPE_ERROR -6
// # define ARG_ERROR -7
# include <errno.h>

typedef struct s_cmds
{
	char	***arg;
	char	**path;
	char	**cmd_arg;
	int		nb_pr;
}	t_cmds;

typedef struct s_mall
{
	char	*p;
	int		f;
}	t_mall;

void	pipex(t_cmds *c, pid_t *proc, int pipe_fd[], char **envp);
int		check_file_perm(char *open_file, char *write_file);
int		init_t_cmds(t_cmds *c, int argc, char **envp);

t_mall	*find_path(t_cmds *c, char *arg, int ind);
int		split_cmd(t_cmds *c, char *arg, int ind);
int		find_all_path(t_cmds *c, char **argv, int nb_pr);

void	launch_cmd(t_cmds *c, int pipe_fd[], char **envp, int pr);
int		commands(t_cmds *c, int r_w_fd[], char **envp);
void	search_cmd(t_cmds *c);

int		free_all_pipex(t_cmds *c, pid_t *proc );
void	print_cmd_i(t_cmds *c, int i);
void	free_t_cmd(t_cmds *c);
int		send_error(int flag);

int		write_file(int r_w_fd[]);
#endif