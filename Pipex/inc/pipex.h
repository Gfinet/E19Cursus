/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfinet <gfinet@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:22:48 by gfinet            #+#    #+#             */
/*   Updated: 2024/04/02 15:50:27 by gfinet           ###   ########.fr       */
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

//main_pipex.c
int		free_all_pipex(t_cmds *c, pid_t *proc );
void	free_t_cmd(t_cmds *c);
void	open_file(int argc, char **argv, int r_w_fd[]);

//init_find_path.c
int		split_cmd(t_cmds *c, char *arg, int ind);
int		init_t_cmds(t_cmds *c, int argc, char **envp);
t_mall	*set_t_mall(char *p, int f);
t_mall	*find_path(t_cmds *c, char *arg, int ind);
int		find_all_path(t_cmds *c, char **argv, int nb_pr);

//cmd_pipe.c
void	launch_cmd(t_cmds *c, int pipe_fd[], char **envp, int pr);
void	print_cmd_i(t_cmds *c, int i);
void	pipex(t_cmds *c, pid_t *proc, int pipe_fd[], char **envp);
int		commands(t_cmds *c, int r_w_fd[], char **envp);

//handle_erroc.c
int		check_file_perm(char *open_file, char *write_file);
int		send_error(int flag);
void	search_cmd(t_cmds *c);

#endif