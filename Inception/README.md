# 42 Project - Inception


## Docker learning notes

### Difference between Docker and VMware

1. Level of virtualization
    - VM virtualizes hardware
    - Docker virtualizes operating system

2. Kernal
    - VM runs on its own kernal
    - Dockers use the same kernal as what the server is using, but each of them has separated CPU, HardDisk, RAM. That's is why Docker are way much faster and lighter then VM.

### How Docker works

1. Docker can pull different "images file", called container. In each container, they are like a tiny VM that has a already configured environment and resources to exec the program that it is suppose to do.
2. The Docker network allows each isolated containers to communicate via "ports"
3. Several examples of container types:
    a. NGINX: works as a webserver that request to and translate response using HTTP.
    b. WordPress: content management interface
    c. SQLDB: database
