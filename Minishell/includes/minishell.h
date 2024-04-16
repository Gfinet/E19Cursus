/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvodak <lvodak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:09:46 by lvodak            #+#    #+#             */
/*   Updated: 2024/04/16 15:02:51 by lvodak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/headers/libft.h"
# include "libft/headers/ft_printf.h"

# include <stdio.h>
// printf, strerror, perror,
# include <readline/readline.h>
# include <readline/history.h>
// readline, (rl_)clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history
# include <sys/signal.h>
// signal, sigaction, sigemptyset, sigaddset
# include <sys/wait.h>
// wait, waitpid, wait3, wait4
# include <unistd.h>
// write, access, open, read, close, fork, dup, dup2, pipe
// isatty, ttyname, ttyslot, getcwd, execve, unlink
# include <stdlib.h>
// malloc, free, getenv
# include <curses.h>
# include <term.h>
# include <termios.h>
// tcsetattr, tcgetattr, tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs
# include <sys/ioctl.h>
 // ioctl
# include <dirent.h>
// opendir, readdir, closedir,
# include <sys/stat.h>
// stat, lstat, fstat

/* exit, kill, chdir, , unlink, */
# define GREEN "\033[0;32m\x1b[1m"
# define LBLUE "\033[0;36m\x1b[1m"
# define BLUE "\033[0;34m\x1b[1m"
# define RED "\033[0;31m\x1b[1m"
# define WHITE "\033[0;30m"
# define NC "\033[0m"

# define WORD_TK 13
# define PIPE_TK 14
# define WRITE_TK 15
# define APPEN_TK 16
# define READ_TK 17
# define HEREDOC_TK 18
# define ENV_VAR_TK 19

typedef struct s_arg_lst
{
	char				*token;
	int					type;
	struct s_arg_lst	*next;
}	t_arg_lst;

typedef	struct s_input
{
	char				*token;
	int					type;
	t_arg_lst			*arg;
	struct s_input		*next;
}	t_input;

int		is_white_space(char c);
int		is_not_sep(char c);
int		closed_quotes(char *str);
int		check_for_pipe(char *str);
t_input	*parse(char *str);

#endif

//getcwd >> useful to print the current directory path