/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unix_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 18:38:02 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/25 18:36:06 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_allpath(char **env)
{
	int		i;
	char	*path_all;
	char	**paths;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path_all = ft_strtrim(env[i], "PATH=");
			paths = ft_split(path_all, ':');
			free(path_all);
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*ft_get_path(char *file, char **env)
{
	char	**paths;
	char	*path;
	char	*exec;
	int		i;

	paths = ft_get_allpath(env);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		exec = ft_strjoin(path, file);
		free(path);
		if (!access(exec, X_OK | F_OK))
		{
			ft_free_all(paths);
			return (exec);
		}
		free(exec);
	}
	ft_free_all(paths);
	return (ft_strdup(file));
}

int	ft_exec(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	if (!cmd)
		return (-1);
	path = ft_get_path(cmd[0], env);
	if (!path)
	{
		ft_free_all(cmd);
		return (-1);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_err6_cmd(path);
		ft_free_all(cmd);
		free(path);
		exit(6);
	}
	ft_free_all(cmd);
	free(path);
	return (0);
}

void	ft_free_all(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	ft_err6_cmd(char *path)
{
	dup2(ERR, OUT);
	ft_printf("%s: command not found: %s\n", P_NAME, path);
}
