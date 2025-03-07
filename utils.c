/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:27:33 by azorlutu          #+#    #+#             */
/*   Updated: 2025/02/16 16:27:37 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *file, int i)
{
	int	fd;

	fd = 0;
	if (i == 0)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		error(file, errno, 123);
	return (fd);
}

void	wait_child(pid_t pid)
{
	int	status;
	int	exit_code;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		exit_code = WEXITSTATUS(status);
		if (exit_code != 0)
			exit(exit_code);
	}
}

static	char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*temp_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	execute_command(char *argv, char **envp)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	path = find_path(command[0], envp);
	if (!path)
	{
		error(command[0], EINVAL, 127);
		while (command[++i])
			free(command[i]);
		free(command);
	}
	if (execve(path, command, envp) == -1)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		error("Execve failed", errno, EXIT_FAILURE);
	}
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	write(1, "> ", 2);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
