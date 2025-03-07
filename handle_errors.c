/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azorlutu <azorlutu@student.42istanbul      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:42:49 by azorlutu          #+#    #+#             */
/*   Updated: 2025/02/17 21:42:50 by azorlutu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *message, int error_code, int exit_code)
{
	if (error_code == EACCES)
		exit_code = 126;
	else if (error_code == EINVAL)
		exit_code = 127;
	errno = error_code;
	if (error_code == EINVAL)
	{
		write(2, message, ft_strlen(message));
		write(2, ": command not found\n", 20);
	}
	else
	{
		write(2, "pipex: ", 7);
		perror(message);
	}
	exit(exit_code);
}

static size_t	char_count(char *str, char ch)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ch)
			count++;
		i++;
	}
	return (count);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5)
		error("Usage: ./pipex infile cmd1 cmd2.. outfile\n", EINVAL, ENOENT);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			error("Usage : ./pipex_bonus here_doc eof cmd1 cmd2.. outfile",
				EINVAL, ENOENT);
		i = 3;
	}
	else
		i = 2;
	while (i < argc - 1)
	{
		if (char_count(argv[i], ' ') == ft_strlen(argv[i]))
			error("Command not found", ENOENT, 127);
		if (char_count(argv[i], '.') > 0)
			error("Command not found", ENOENT, 127);
		if (char_count(argv[i], '/') == ft_strlen(argv[i]))
			error("Command not found", ENOENT, 127);
		i++;
	}
}
