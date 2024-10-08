# 42 Common Core - WebServ

### Stateless protocal vs Stateful Protocal
- Stateless Protocal: 
	1. Do not retain session state from previous requests.
	2. Pros:
		- Visibility: it doesn't have to look beyond a single request to complete its task
		- Reliability: it eases the task of recovering from partial failures
		- Scalability: it doestn't have to store session state and allows server to quickly free resources.
	3. cons: 
		- could decrease performance by increasing the repetitive data sent in each request.
	4. Examples: HTTP (HyperText Transfer Protocal), IP (Internet Protocal)
- Stateful Protocal:
	1. A comminucation protocal in which the receiver may retain session state from previous requests
	2. Examples: TCP (Transmission Control Protocal), FTP (File Transfer Protocal)
- Stacking of stateless and stateful protocal layers
	1. There can be complex interactions between these two protocals.
	2. Ex:
		- HTTP (stateless) on top of
		- TCP (stateful) on top of
		- IP (stateless) on top of
		- BGP (stateful) (Border Gateway Protocal)

### What can an HTTP control?

1. Caching: How documents are cached can be controlled by HTTP. The server can instruct proxies and clients about what to cache and for how long. The client can instruct intermediate cache proxies to ignore the stored document.
2. Relaxing the origin constraint: To prevent snooping and other privacy invasions, Web browsers enforce strict separation between websites. Only pages from the same origin can access all the information of a Web page. Though such a constraint is a burden to the server, HTTP headers can relax this strict separation on the server side, allowing a document to become a patchwork of information sourced from different domains; there could even be security-related reasons to do so.
3. Authentication: Some pages may be protected so that only specific users can access them. Basic authentication may be provided by HTTP, either using the WWW-Authenticate and similar headers, or by setting a specific session using HTTP cookies.
4. Proxy and tunneling: Servers or clients are often located on intranets and hide their true IP address from other computers. HTTP requests then go through proxies to cross this network barrier. Not all proxies are HTTP proxies. The SOCKS protocol, for example, operates at a lower level. Other protocols, like ftp, can be handled by these proxies.
5. Sessions: Using HTTP cookies allows you to **link requests with the state of the server.** This creates sessions, despite basic HTTP being a state-less protocol. This is useful not only for e-commerce shopping baskets, but also for any site allowing user configuration of the output.


