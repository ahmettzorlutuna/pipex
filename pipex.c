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

#include "pipex.h"

static	void	create_child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error("Failed to create pipe", errno, EXIT_FAILURE);
	pid = fork();
	if (pid == -1)
		error("An error occurred while forking", errno, EXIT_FAILURE);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute_command(argv, envp);
	}
	else
	{
		wait_child(pid);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	child_process_count;
	int	infile;
	int	outfile;

	check_args(argc, argv);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		child_process_count = 3;
		outfile = open_file(argv[argc - 1], 0);
		read_here_doc(argv[2]);
	}
	else
	{
		child_process_count = 2;
		infile = open_file(argv[1], 2);
		outfile = open_file(argv[argc - 1], 1);
		dup2(infile, STDIN_FILENO);
	}
	while (child_process_count < argc - 2)
		create_child_process(argv[child_process_count++], envp);
	dup2(outfile, STDOUT_FILENO);
	execute_command(argv[argc - 2], envp);
}
