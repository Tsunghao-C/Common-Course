/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_ref.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuchen <tsuchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 00:19:18 by tsuchen           #+#    #+#             */
/*   Updated: 2024/09/10 00:20:58 by tsuchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

// Function to write an error message to stderr
void	err(char *str)
{
    // Loop through each character in the string and write it to stderr
    while (*str)
        write(2, str++, 1);
}

// Function to change the current working directory
int cd(char **argv, int i)
{
    // If the number of arguments is not 2, print error and exit
    if (i != 2)
        return err("error: cd: bad arguments\n"), 1;
    // If changing the directory fails, print error and exit
    if (chdir(argv[1]) == -1)
        return err("error: cd: cannot change directory to "), err(argv[1]), err("\n"), 1;
    return 0;
}

// Function to set pipe
// end == 1 sets stdout to act as write end of our pipe
// end == 0 sets stdin to act as read end of our pipe
void set_pipe(int has_pipe, int *fd, int end)
{
	if (has_pipe && (dup2(fd[end], end) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		err("error: fatal\n"), exit(1);
}

// Function to execute a command
int exec(char **argv, int i, char **envp)
{
    int has_pipe, fd[2], pid, status;

    // Check if the command includes a pipe
    has_pipe = argv[i] && !strcmp(argv[i], "|");

    // If the command is 'cd', execute it
    if (!has_pipe && !strcmp(*argv, "cd"))
        return cd(argv, i);

    // If the command includes a pipe and creating the pipe fails, print error and exit
    if (has_pipe && pipe(fd) == -1)
        err("error: fatal\n"), exit(1);

    // Fork the process and if the fork fails, print error and exit
    if ((pid = fork()) == -1)
	err("error: fatal\n"), exit(1);
    if (!pid)
    {
        argv[i] = 0;
        // If the command includes a pipe, set write end of pipe, if it fail print error and exit
        set_pipe(has_pipe, fd, 1);
        // If the command is 'cd', execute it
        if (!strcmp(*argv, "cd"))
            exit(cd(argv, i));
        // Execute the command
        execve(*argv, argv, envp);
        // If executing the command fails, print error and exit
        err("error: cannot execute "), err(*argv), err("\n"), exit(1);
    }

    // Wait for the child process to finish
    waitpid(pid, &status, 0);
    // If the command includes a pipe, set write end of pipe, if it fail print error and exit
    set_pipe(has_pipe, fd, 0);
    // Return the exit status of the child process
    return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int ac, char **argv, char **envp)
{
    int    i = 0, status = 0;

    if (ac < 2)
	    return (0);
    // Loop through each following argument
    while (argv[i])
    {
        // Move the pointer to the next argument after the last delimeter / first argument
    	argv += i + 1;
    	i = 0;
        // Loop through each argument until a pipe or semicolon is found
    	while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
        // If there are arguments, execute them
    	if (i)
			status = exec(argv, i, envp);
    }
    return status;
}
