/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:10:30 by tsuchen           #+#    #+#             */
/*   Updated: 2024/07/07 17:46:34 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	int	tmpin;
	int	tmpout;
	int	fdin;
	int	fdout;
	int	pid;
	int	fdpipe[2];

	tmpin = dup(STDIN_FILENO);
	tmpout = dup(STDOUT_FILENO);

	//set initial input
	if (infile)
		fdin = open(infile, O_RDONLY);
	else
		fdin=dup(tmpin);
	for (i = 0; i < num_of_cmds; i++)
	{
		//redirect input
		dup2(fdin, STDIN_FILENO);
		close(fdin);
		//set output
		if (i == num_of_cmds - 1)
		{
			//Last command
			if (outfile)
				fdout = open(outfile, O_WRONLY | O_CREAT, 0777);
			else
				fdout = dup(tmpout);
		}
		else
		{
			//Not last cmd: create pipe
			pipe(fdpipe);
			fdout = fdpipe[1];
			// set fdin for the next iteration
			fdin = fdpipe[0];
		}
		//redirect output
		dup2(fdout, STDOUT_FILENO);
		close(fdout);
		//Create child process
		pid = fork();
		if (pid == 0)
		{
			execvp(cmd[i].arg[0], cmd[i].args);
			perror("execvp");
			exit(1);
		}
	}
	//restore in/out to defaults (important if this is a minishell program!!)
	dup2(tmpin, STDIN_FILENO);
	dup2(tmpout, STDOUT_FILENO);
	close(tmpin);
	close(tmpout);
	//wait for last command
	if (!background)
		waitpit(pid, NULL);
}

/* Build In Functions */
// for all Built-in functions execpt "printenv" are executed by parent process, not child precess.
// Because Built-in functions may change "environment variables" and we want to keep the "envs"
// to each child process. If they are processed in child processes, the chages will be gone!

/* Wildcards */

