# 42 Common Core Project - Philosophers

## Objective

1. This project is about developing parallel tasks using "Threads"
2. To a more advanced level, also know the differences between processes and threads, and try to do the same thing with processes.

## Key Concepts

1. What is threads and how does it work? Why do we use it?
2. What is MUTEX? Why it matters in threads?

## The difference between THREAD and PROCESS
    1. THREAD shares memories but PRCOESSES don't
    2. A PROCESS can contain multiple THREADS, but a thread can only belong to one PROCESS.

### Deadlock
    1. Deadlock is a situation when the thread(s) stay constantly waiting for unlock, which could never happen.
    2. Types of deadlock situations:
        1. There are more ```pthread_mutex_lock``` than ```pthread_mutex_unlock```
        2. There are more than one MUTEX but the order of the MUTEX are not consistent
            ex: suppose there are two mutex and there are 2 threads running the following routine:
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
