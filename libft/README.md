# 42 Common Core Project - libft

## Objective

1. Learn to build your own library.
2. Replicate the functions in libc, and some useful functions for array management
3. For bonus part, add useful linked list functions as well.

## Key Concept

1. How to script Makefile
2. Know how each function should behave in boundary situations
3. Whether to protect input or not?

## Remark

1. For the part 1 functions that is to replicate libc funcitons, you need to have the same behavior to the real ones.
2. As for the part 2 and the bonus part, it is actually up to you to decide wether you want to protect input (if it is NULL) or not. For me, I choose not to protect the input because if the input variable is incorrect, I should trace the previous step and figure out why the input went worng. I think it is more reasonable and easier to debug in the future. But again, people have different preferences and there is no "correct" answer.
3. Make sure to free_all allocated memories if there is an error happend, especially in linked list and array of strings.
