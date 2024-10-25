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

1. Docker can pull different "images file", which is a read-only configuration that is used to build a container. In each container, they are like a tiny VM that has an already configured environment and resources to exec the program that it is suppose to do.
2. The Docker network allows each isolated containers to communicate via "ports"
3. Several examples of container types:
    a. NGINX: works as a webserver that request to and translate response using HTTP.
    b. WordPress: content management interface
    c. SQLDB: database


### Docker Architectur
![alt text](docker-architecture.webp)
picture reference: https://docs.docker.com/get-started/docker-overview/

1. Docker uses a client-server architecture. Like `git`, the client do commands to the service (daemon), and the daemon communicate with the server.
2. The Docker client (usually using `docker`) and Docker daemon (`dockerd`) communicate via: REST API, over UNIX socks or a network interface.
3. `Docker Compose` is another type of Docker client that lets you compose your Docker network consisting of a set of containers.

### Registry VS Repository in Docker

#### **Registry**
1. A **registry** is a storage and content delivery system where Docker images are stored. It's a centralized location that hosts and serves Docker images.
2. Examples of Docker Registries:
    - Docker Hub: The default public registry for Docker images (docker.io)
    - Amazon Elastic Container Registry (ECR): A registry service by AWS.
    - Google Container Registry (GCR): A registry service by Google Cloud.
    - Azure Container Registry (ACR): A registry service by Microsoft Azure.
#### **Repository**
1. A **repository** is a specific image project (or folder) within the registry. Inside each repository, there could be multiple versions (tags) of a specific project.

#### How they work together in cml

**ex.1 when pulling and pushing an image, we need to specify both the registry and repositry:**\
\
`docker push myusername/myrepository:mytag`

- `docker.io` (Docker Hub) is the **default registry**, not showned.
- `myusername/myrepository` is the **repository**.
- `mytag` is the **tag** specifying the image version.

**ex.2 push to private or non-default registry:**\
\
`docker push myprivateregistry.com/myapp:latest`

- `myprivateregistry.com` is the **custom registry**.
- `myapp` is the **repository**
- `latest` is the **tag**.

### Docker Objects
#### **Images**
- An image is a **read-only** template with instructions for **creating a Docker container**.
    1. Images are immutable. Once an image is created, it can't be modified. You can only make a new image according to the changes you make.
    2. Container images are composed of layers of images. Each layer represented a set of file system changes that add, remove, or modify files.
- An image is often based on other images. Ex. you create an image which is based on the `debian` image, and install other applications.
- To build your own image, you create a `Dockerfile` with a simple syntax for defining the steps needed to create the image and run it. **Each instruction in a Dockerfile creates a layer in the image. When you change the Dockerfile and rebuild the image, only those layers which have changed are rebuilt.** This is part of what makes images so lightweight, small, and fast, when compared to other virtualization technologies.
#### **Containers**
- A container is a runnable instance of an image. You can create, start, stop, move, or delete a container.
- A container is by default isolated from other containers and its host machine. You can configure the network connections of a container to other container, storage, or other underlying subsystems.

### Docker Cammands

- Run a container: docker run -d(to detach) -p 8080:80 (set port) [image-id]
- List running containers: docker ps
- List all containers:  docker ps -a
- Stop a container: docker stop
- Remove a container: docker rm [container-name]
- Pull an image: docker pull
- Build an image: docker build
- See iamge list: docker image ls
- Tag an image: docker tag [image-id]
- Push an image to remote docker repo: docker push [username]/[repo-name]
- Remove an image: docker rmi [image-id]
- See logs from a container: docker logs [container-id]

### Docker Compose

- One best practice for using containers is that each container should do only one thing and focus on doing it well. We should avoid the tendency to have one container to do multiple things.
- So, in order to respect this rule, how do we manage multiple containers and make them work at the same time? To do this, we must have a **Network** of containers, and configure how they should interact with each other.
- `Docker Compose` is here to build a net work of containers using a single YAML file. Inside the `compose.yml` file, you have several Dockerfile that build several containers.

#### Commands of Docker Compose

- To build up the docker network: docker compose up -d --build
- To remove the docker network: docker compose down
- To remove the docker network including volumes: docker compose down --volumes

**Volume Persistence**
By default, volumes are not automatically removed when tearing down a composed docker network. The idea is if you want to build up again the service later, you will still have the data back again. Super light weight and portable!


#### VM in 42
- username: tsuchen
- pw: Myinception
