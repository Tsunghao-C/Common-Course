# 42 Common Core Project - get_next_line

## Objective

1. To create a useful function that will fetch the next line of infromation form a givien fild descripton everytime it is called.
2. For bonus part, it should be able handle multiple files at the same time and use only one static variable in the funciton.

## Key Concept

1. Static Variable
2. Use of buffer and buffer size
3. Create an adjustable Macro in header file
4. Error management for possible situations (ex. wrong fd, cannot open, end of the file behavior, etc...)

## My Coding Method

I used a linked list method to script my get_next_line. The static variable is a pointer to a linked list.

I think the advantage of using linked list is that every time you fetch the size of "BUFFER_SIZE" from the file and store it individully, which is more flexible to manage. When it comes to a huge amount of data wihtout a '''\n''', for array you will need a continuous memory for that, which could went wrong sometimes. But the downside of linked list is that for normal or simple tasks, it is not as fast as array method, and you need to pay more attention to free the memory (espacially the static variable) in error situations.
