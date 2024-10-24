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


### Docker Architectur
![alt text](docker-architecture.webp)
picture reference: https://docs.docker.com/get-started/docker-overview/

1. Docker uses a client-server architecture. Like ```git```, the client do commands to the service (daemon), and the daemon communicate with the server.
2. The Docker client (usually using ```docker```) and Docker daemon (```dockerd```) communicate via: REST API, over UNIX socks or a network interface.
3. ```Docker Compose``` is another type of Docker client that lets you compose your Docker network consisting of a set of containers.

#### Docker Objects
1. **Images**
    - An image is a read-only template with instructions for **creating a Docker container**.
    - An image is often based on other images. Ex. you create an image which is based on the ```debian``` image, and install other applications.
    - To build your own image, you create a ```Dockerfile``` with a simple syntax for defining the steps needed to create the image and run it. **Each instruction in a Dockerfile creates a layer in the image. When you change the Dockerfile and rebuild the image, only those layers which have changed are rebuilt.** This is part of what makes images so lightweight, small, and fast, when compared to other virtualization technologies.
2. **Containers**
    - A container is a runnable instance of an image. You can create, start, stop, move, or delete a container.
    - A container is by default isolated from other containers and its host machine. You can configure the network connections of a container to other container, storage, or other underlying subsystems.

#### VM in 42
- username: tsuchen
- pw: Myinception
