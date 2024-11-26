## Elasticsearch Memory Setup

Currently in our transcendance, the elasticsearch is using `single-node` mode.

1. **Current Setup**:
- We're running in `single-node` mode (`discovery.type=single-node`), not a real cluster
- We have just one node called `es01`
- Memory is configured via JVM heap settings (`ES_JAVA_OPTS=-Xms512m -Xmx512m`)

2. **To Scale Memory, you have two options**:

a) **Vertical Scaling** (current setup):
- Simply modify memory settings in the existing node:
```yaml
elasticsearch:
    environment:
      - "ES_JAVA_OPTS=-Xms2g -Xmx2g"  # Increase from 512m to 2g
```

b) **Horizontal Scaling** (requires architecture change):
- Remove `discovery.type=single-node`
- Configure proper cluster settings
- Add multiple nodes like this:
```yaml
elasticsearch-1:
    # Master + data node
    environment:
      - node.name=es01
      - cluster.name=pong-game-logs
      - node.roles=[master,data]
      - discovery.seed_hosts=elasticsearch-2,elasticsearch-3
      - cluster.initial_master_nodes=es01,es02,es03

elasticsearch-2:
    # Data node
    environment:
      - node.name=es02
      - cluster.name=pong-game-logs
      - node.roles=[data]
      - discovery.seed_hosts=elasticsearch-1,elasticsearch-3

elasticsearch-3:
    # Data node
    environment:
      - node.name=es03
      - cluster.name=pong-game-logs
      - node.roles=[data]
      - discovery.seed_hosts=elasticsearch-1,elasticsearch-2
```

3. **Volume Configuration**:
- Volumes are for data persistence
- Changing volume settings doesn't affect memory allocation
- Each node needs its own volume for data

So, if you want to increase available memory, you need to either:
1. Increase the JVM heap size for vertical scaling (single node)
2. Or switch to a proper cluster setup for horizontal scaling (multiple nodes)

Would you like me to explain how to implement either of these approaches in more detail?