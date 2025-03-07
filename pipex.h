/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 19:20:58 by azorlutu          #+#    #+#             */
/*   Updated: 2025/02/15 19:21:05 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "./Libft/libft.h"

void	execute_command(char *argv, char **envp);
void	error(char *message, int error_code, int exit_code);
void	check_args(int argc, char **argv);
void	wait_child(pid_t pid);
void	read_here_doc(char *limiter);

int		get_next_line(char **line);
int		open_file(char *file, int i);

#endif
