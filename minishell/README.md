# 42 Common Core Project - MINISHELL

## Objective

1. This is an advanced Unix project that we create a simplified shell program.
2. The goal is to replicate an interactive shell that can really execute commands and programs!

## Key Concepts

1. Parsing and lexing the inputs in the terminal. Need to do 2 to 3 steps by proper identifying the META characters and group or exapand the input into reasonable subgroups before execution.
2. Fundamental Unix process knowledge: child process, pipes, FD redirection, signal handeling
3. Built-in functions in shell and their behaviours.
4. Error handling by tracking exit code
5. The choice of data structure and build up a program based on that.
6. Cooperation with teammates using github and git tools.
7. Use enum and tokenized Macros to make codes more readable.

## Notes of this big and challenging project

Link to our minishell git repo: https://github.com/nyzss/minishell.git

### Shout out
- First of all, great shout out to my teammate Okan. He was such a good teammate who had had done a lot of research on how to build the minishell. Without him, I could have spent 2 or more weeks on how to do this project, especially the parsing and lexing part.
- Second shout out to the youtube channel of Codevault. I finished watching every video in the Unix playlist. It was super helpful and easy to understand. 
### Cooperation
- I had a gread co-working experience with Okan. I think a key point is that we spent some time at the beginning to discuss the scope of this project and how to split the works. Most importantly, we draft the general header first and some of the key data structures that he will pass to me after parsing and lexing.
- It was also my first time using github a lot to co-work a project. Even though we didn't use the git properly and always push and pull to the main (which is a very dangerous way actually), thankfully we split our works well and we were both very carefull on each commit so no disater happened.
### Data Structure
- We used a lot of linked list in the end. To us it was the easiest and straight forward way to handle a groups of informations.
- There is another solution of using binary tree as the data structure. I think it would be more efficient and useful for the bonus part where you need to handle "&&" "||" and parenthesis, but we did not spend extra time to explore binary tree and linked list work just fine.
### The timing and order matters!
- Once you realize that scope of minishell and what you need to do, you will realize it is not too hard to code them, but what is the correct order and timing to do certain tasks that matches the real bash.
- Here are the lessons learned in our experience
    1. [Parsing and Lexing] Identify the META characters and group them properly.
    2. [Parsing and Lexing] If there is here_doc, you need to handle here_doc first and then consider it as an INFILE before starting the exec part.
    3. [Exec] In each executable sets (ie. within a a process), first handle FD redirections and then do the exec.
    4. [Exec] ~~The number of pipes should in accordance to the number of "|" dectected from input. Common mistakes are people tried to create an additional pipe for the last executable set in the child process. You still need to create a fork() for the last cmd but don't create additional pipe!!!~~ [20240924 update] The number of pipes should be the same of the number of forks to make sure that the parent process always have a channel to communicate with the last child process. You can use ``` strace -e trace=pipe2 bash --posix ``` to see how many pipes are created in Bash Posix.
    5. [Built in] If the cmd is a built-in function and there is just only on cmd, the built in function shall be called in parent process. Otherwise, you still create a fork and call built-in in child process.
    6. [Built in] For the *env* double pointer, it is highly recommended to transform it to a linked list. It will be much easier to handle for "export" and "unset" function that you need to add or remove content in the *env*.
    7. [Exec] Use waitpid and track the exit_code of each child process. By doing so you can identify whether a child processs is terminated successfully, failed, or killed by signal, and you can react accordingly.
