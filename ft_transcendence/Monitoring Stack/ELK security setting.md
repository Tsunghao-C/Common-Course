
## Understand trasport context
1. **Transport Layer Securit (TLS)** is the name of an industry standard protocol for applying security controls lke encryption to network communications. It is the modern name for **Secure Sockets Layer (SSL)**.
2. ELK uses default `9300` for **Transport Port** and default `9200` for **HTTP Port**.
    - Transport port: Nodes communication with one another
    - HTTP port: REST clients communication

### Set up Encrypted communication between nodes in Elasticsearch

In this project, we have settled:
1. Transport Layer Security (TLS) encryption for all internal communication
2. Mutual authentication between components using certificates
3. Basic authentication (for admin) with username and password
4. X-Pack security features in Elasticsearch and Kibana
5. TLS for external access to Kibana, and keep kibana the only external entrypoint.

### Future in-depth security settings for each service
1. Elasticsearch:
 - Role-Based Access Control (RBAC) to limit what different users can do
 - Index lifecycle management policies to handle sensitive data retention
 - Field-level security to restrict access to specific data fields
 - Audit logging to track who's accessing what

2. Kibana:
 - Spaces to separate different teams' dashboards and visualizations
 - Security roles that align with Elasticsearch's RBAC
 - Session timeout settings to automatically log out inactive users
 - IP filtering to restrict access to specific networks

3. Logstash:
 - Dead letter queues to handle failed log entries securely
 - Pipeline labels to separate different types of logs
 - Filter plugins to remove sensitive information before storage
 - Input/output plugins validation to prevent injection attacks

4. Filebeat:
 - Log rotation policies to manage disk space and data retention
 - Input validation to reject malformed log entries
 - Module-specific security settings for different log sources
 - Secure registry file permissions