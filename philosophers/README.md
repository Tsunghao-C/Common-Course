# 42 Common Core Project - Philosophers

## To do list

1. ~~Use pthread_detach to terminate program when any of the philosopher dies.~~
2. ~~Find a way to continuously checking dead or alive even when waiting or usleep.~~
3. ~~Norminette check~~
4. ~~Consider whether I should detach each philosopher or detach the starvation_check thread.~~
5. Check extreme cases when time_to_die is very close to 2 * time_to_eat for even philos.
6. ~~Need to add MUTEX on EVERY Variable in the struct that could be updated over time!!!~~
7. ~~Fixed data race on printf (STDOUT) and checking setting.dead and setting.last_meal~~
8. ~~Use Helgrind to check if there is any thread errors~~
9. Find out why using helgrind the philo won't work properly. (Looks like usleep is not functioning well when calling valgrind)

## To do list BONUS

1. review thinking time so that philo_bonus 3 200 1000 100 should at least eat one time

## Objective

1. This project is about developing parallel tasks using "Threads"
2. To a more advanced level, also know the differences between processes and threads, and try to do the same thing with processes.

## Key Concepts

1. What is threads and how does it work? Why do we use it?
2. What is Race Condition? Why it matters in threads?
3. What is MUTEX? What is deadlock?
4. What is SEMAPHORE and why do we use it? How is it different to MUTEX?
5. What do CONCURRENCY and PARALLELISM mean in programming?

### The difference between THREAD and PROCESS

1. THREAD shares memories but PRCOESSES don't
2. A PROCESS can contain multiple THREADS, but a thread can only belong to one PROCESS.

### Race Condition

1. Race conditions happens in concurrency.
2. When multiple threads are using the same resource (reading and writing a variable maybe), chances are multiple threads try to access (read) or update (write) the resource at the same time which could lead to data overwrite.
|Table  |Thread 1   |Thread 2   |rsc    |
|-------|-----------|-----------|-------|
|Initial|start      |start      |2      |
|access |2          |2          |2      |
|process|2 + 1 = 3  |2 + 1 = 3  |2      |
|update |rsc = 3    |rsc = 3    |3      |

In the table above, the rsc should be 4 after being processed twice, but the result is 3 instead. It is because both threads didn't use the resource in the proper order so the rsc is not updated correctly.

3. The solution to race condition is applying a LOCK SYSTEM on the shared resources to make sure the resources are used once at a time. The LOCK SYSTEM can be
    a. MUTEX (Mutual Exclusion Lock)
    b. Semaphores

### Deadlock

1. Deadlock is a situation when the thread(s) stay constantly waiting for unlock, which could never happen.
2. Types of deadlock situations:
    1. There are more ```pthread_mutex_lock``` than ```pthread_mutex_unlock```
    2. There are more than one MUTEX but the order of the MUTEX are not consistent
    Ex: suppose there are two mutex and there are 2 threads running the following routine:
```
pthread_mutex_t mutexA
pthread_mutex_t mutexB

void    *routine(void *arg)
{
    if (rand() %2 == 0)
    {
        pthread_mutex_lock(&mutexA);
        pthread_mutex_lock(&mutexB);
    }
    else
    {
    pthread_mutex_lock(&mutexB);
    pthread_mutex_lock(&mutexA);
    }
}
```
If thread 1 happen to start mutexA first and tread 2 start with mutexB, it will reach to a deadlock that both of the threads are waiting each other to do the second lock
| Table   | MutexA    | MutexB |
|---------|-----------|--------|
| Thread 1| lock      | waiting|
| Thread 2| waiting   | lock   |


### Concurrency vs Parallelism
- **Concurrency** is when two or more tasks can start, run, and complete in overlapping time periods. It doesn't necessarily mean they'll ever both be running at the same instant. For example, multitasking on a single-core machine.
- **Parallelism** is when tasks literally run at the same time, e.g., on a multicore processor.

#### More explanations about Concurrency and Parallelism

1. Parallelism means all threads are processes INDEPENDENTLY. They don't share a common memory are source.
2. Concurrency means all there are common memory or resouces shared by each thread. All the threads can be running at the same time, BUT when it comes to using the shared memory, they need to queue.

#### RULE of THUMB when structuring a program in terms of performance

1. Parallelism is always more efficient than concurrency. Should try to make each thread as independent as possible.
2. If concurrency if inevitable, always try to minimized the degree of concurrency.
3. Make sure EVERY RESOURCES used in concurrency program must be handled with synchronization tools like mutex or semaphore. (Even the STDOUT used by printf needs to be handled)
4. Be sure to wait (join) every lead before destroying a mutex or syncronization object. Otherwise, there could be data race.

### Semaphore

1. Semaphores is a library that can create a semaphore object which is initialized with a number (sem_int).
2. Combined with the use of sem_wait and sem_post, it can work like a lock as mutex:
    a. sem_wait: if num == 0 then wait, else decrement the sem_int and continue.
    b. sem_post: increment the sem_int and continue.

#### Difference between Semaphore and MUTEX

1. MUTEX is expected to **lock and unlock within a same thread**. Otherwise, the behaviour is undefined.
2. Semaphore is index based using a semaphore object. It can lock (sem_wait) and unlock (sem_post) in different threads.
3. MUTEX can be considered as a kind of **binary semaphore** that should be used in pair in a thread. Semaphore is more general in dealing with concurrency tasks.

