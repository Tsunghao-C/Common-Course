### Who's PID 1 in the container?

1. Each Docker container is a PID namespace, which means that the processes in your container are isolated from other processes on your host. A PID namespace is a tree, which starts at PID 1, which is commonly called `init`.

1. By default, when you run a Docker container, PID 1 is whatever you set as you `ENTRYPOINT`, or if you don't have one, then it's either your shell or your program depending on how you use `CMD`.
2. For example
    - `CMD python3 my_program.py`: by using the shell format, the container will start running `sh -c python my_program.py`. **The shell is thus pid 1**.
    - `CMD ["python3", "my_program.py"]`: by using exec format, the container will run directly the program, and in this case **python3 will thus be pid 1**.
**Note**: If you don't want to go throuhg with shells, **always use the exec format!**

### Why Letting program PID 1 in Container is an issue?
- If you let `python` for example as PID 1 in the container, every time you call the container, it will create and orphaned zombie process it cannot reap.


### Is Bash the answer to the PID 1 in Container?

1. Not entirely. If you init the container via `bash`, the bash will be the PID 1, and can `reap child processes` avoid zombie processes from filling up the kernel process resouce table.
#### Downside
1. Bash is poor at propagate signals. If it receives the signal `SIGTERM` from `Docker stop`, the application process will not shutdown. After 10 seconds, docker will send `SIGKILL` to bash and that's a problem!!!
2. In order to handle signals, you need to add a script to **trap the signals** and pass it to the application for a clean exit.
3. Example bash Script;
```
!/bin/bash

/web.py &
PID=$!
trap "kill $PID" INT TERM
wait
```

### PID 1 issue recap
1. Orphaned zombie processes were not properly reaped if program is the PID 1.
2. Handling of signals if shell is PID 1.

### Options for handling PID 1 issue in container

##### Solution 1: Let bash to be PID 1 with signal handling script
##### Solution 2: Use existing init softwares instead
    - Tini
    - Dumb-init
##### Solution 3: Always use `--init` Flag when doing `Docker run`
    - This is equivalent to boot up `Tini`, a lightweight init system in the container as PID 1.
##### Solution 4: Add Systemd in conatainer and run systemd
1. Systemd can run inside a container whthout the privileged mode.
2. Systemd can handle logging
3. Example:
```
FROM centos:latest
USER root
ADD web.py /web.py
ADD web.service
/usr/lib/systemd/system
RUN chmod +x /web.py && systemctl enable web.service
CMD ["/sbin/init"]
STOPSIGNAL SIGRTMIN+3
```

### Conclusion

1. If you follow the rule of thumb that each container only do one simple tast:\
    1. use `ENTRYPOINT` or `CMD` in exec form
    2. Always use `Docker run --init` with the `--init` flag
2. If you really want to have multiple processes in the container, init the container with a bash script that can handle Signals.
3. If you want to have more advance system feature, and you have enough resouce to accomodate systemd, consider to add Systemd in the container.


### References

1. https://cloud.theodo.com/en/blog/docker-processes-container
2. https://hasgeek.com/rootconf/2017/sub/what-should-be-pid-1-in-a-container-JQ6nkBv13XeZzR6zAiFsip
3. https://daveiscoding.hashnode.dev/why-do-you-need-an-init-process-inside-your-docker-container-pid-1
