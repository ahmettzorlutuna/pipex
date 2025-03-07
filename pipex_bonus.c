/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:52:58 by azorlutu          #+#    #+#             */
/*   Updated: 2025/02/26 19:52:59 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_here_doc(char *limiter)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	if (pipe(fd) == -1)
		error("Failed to create pipe", errno, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		error("An error occurred while forking", errno, EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		wait_child(pid);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
