# 42 Common Core - WebServ

## Objective

1. This is my first Web related project in 42 common course, building a simple Web Server from scratch using C++98.
2. The goal is to learn the basic client-Server structure and write a program that work as a werver.

## Key Concepts

1. What is a web server? Why is it called "Server" anyway? What actually happens when using a browser to connect to the Internet?
2. The structure of client-Server. How user (Client) and Server communicate?
3. What is HTTP? What does an HTTP Request or Response look like?
4. Parsing of Configuration files and set up Sever/Cluster structure.
5. What is Epoll and what does it mean by "Non-blocking" reading and writing? Why it matters in a server program?
6. Parsing of HTTP string and generating string in HTTP fashion.
7. What is CGI and how does it work? Why we use it?
8. The file system in the server and how do you configure your server to prevent malicious client request (ex. wrong content length, trying to access or destroy stuffs in the server)
9. What is "Cookie" and how does it work?
10. Learn how to write scripts and test your server program

## Notes

Link to our Webserv git repo: https://github.com/BenjaminHThomas/WebServer.git

### Shout out
- It's a pleasure to work with Okan, my previous teammate in Minishell, and also Ben who is really smart and good at explaining complex ideas in a simple way.
- Thanks to Okan, who has already studied on this project for almost a month and know how to split the job into three, we had a good start and be able to put together our codes and submit in two weeks.

## Notes about learning Web and HTTP

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


