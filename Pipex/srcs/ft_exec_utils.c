/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:08:10 by tsuchen           #+#    #+#             */
/*   Updated: 2024/06/28 14:22:11 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exec(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split_quote(av, ' ');
	if (!cmd)
		return (-1);
	if (!cmd[0])
		path = ft_get_path(av, env);
	else
		path = ft_get_path(cmd[0], env);
	if (!path)
	{
		ft_free_all(cmd);
		return (-1);
	}
	if (execve(path, cmd, env) == -1)
	{
		ft_err6_cmd(path, errno);
		ft_free_all(cmd);
		free(path);
		return (-1);
	}
	ft_free_all(cmd);
	free(path);
	return (0);
}

char	*ft_get_path(char *file, char **env)
{
	char	**paths;
	char	*path;
	char	*exec;
	int		i;

	if (!env || ft_isabs_path(file) == 1)
		return (ft_strdup(file));
	paths = ft_get_allpath(env);
	if (!paths)
		return (ft_strdup(file));
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

int	ft_isabs_path(char *file)
{
	while (*file)
	{
		if (*file++ == '/')
			return (1);
	}
	return (0);
}

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
