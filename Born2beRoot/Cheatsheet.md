# Notes for learning Virtual Machine and OS

## Virtual Machine

### What is virtual machine?

Virtual machine is a virtual operating environment that is created by #Hypervisor# software. It request certain amount of hardware resources (CPU, RAM, Storage) from the host and create a virtual machine. The machine created won't realize it is a virtual one.

### What's the benefits of using virtual machine?

1. It's a virtual space. Safer to do experiments or crash it.
2. You can install whatever operating systems you like.
3. Totally isolated to the host system (depends on the settings). Often used by hacking.

### Types of Hypervisors

1. Type 1: Hypervisor based on an OS. Usually personal use.
2. Type 2: Hypervisor dirctly on server. Coprate or organization use.

## Linux System

### What is Debian?

1. Debian GNU/Linux is one of the oldest Linux distribution (an OS that includes Linux kernal and package management system).
2. The Debian Stable branch is the most popular edition for PC and Servers. It is also the basis for many other Linux distributioins in different purposes. For instance:
    - servers:          Proxmox
    - desktops:         Ubuntu, Linux Mint
    - penetration test: Kali
    - goverment:        Pardus, Astra

### What is apt?

1. APT stands for Advance Package Tool. It is a free-software user interface to handle installation and removal of software on Debian-based Linux distributions.
2. Common used apt commands:
    - apt-get:          to install software
    - apt-cache         to search for the info of a software
3. Aptitude is a front end software to APT. In a nutshell, it has better user interface and more concise commands compared to APT.

## Security SELinux vs AppArmor

1. SELinux stands for Security Enhanced Linux. It is a mandatory access control system, meaning it enforces the security Policies that you define (a rule book) that applications must follow and there are no exceptions to that.
2. Apparmor, on the otherhand, takes a Profile-based approach, that it gives every application a "Profile", or a specific set of permissions, defining what this app can or cannot do.It focuses more on the file access control and it more user-friendly.
3. In a nutshell, SELinux is more like a Constitutional way, and Apparmor is a case-by-case profile.

reference: https://www.youtube.com/watch?v=xeZI55o2LKs

## LVM

### What is LVM?

1. LVM stands for Logic Volume Management. It first collect all your physical hard drive storage and create a colloective storage space called "Volume Group".
2. Then, you can do storage partitions on top of the volume group that is called Logical Volumes.

### Why we use LVM?

1. Imagine that you have a hard drive of 120GB, and you do the partition without LVM. Then, a few days later you find out that you are running out of space, and you would like to expand the storage with another hard drive. You will have to back up everything stored right now, format your hard drive, and then do partition again with all the space you have.
2. What if you use LVM at the begining? Life would be much easier. All you need to is to add the new extended hard drive in your Volume Group, and then extent the space of your logical volumes as you want with several commands.

reference: https://www.youtube.com/watch?v=214rUhQe7B4

## Daemons & Processes

### What is Daemons?

1. Daemons are like background prcoess (or services) that runs by themselves. They are necessary to keep linux or program running but not directly interact with users.
2. You can use "ps -ax" to see all the current processing processes. The names of processes with a "d" in the end are the daemon processes. Ex. sshd, syslogd, configd, etc...
3. daemons are also being called as "units"
4. Introducing "Systemd", the master of all daemons.
    - systemd is the service manager for all daeman services
    - systemd is the initialization system (or "init", but different to init system)
    - Process of (re)boot a Linux system
        1. Power on (Boot)
        2. Load the Kernel
        3. Kick off systemd (start forking)
            - Mounting file systems
            - Starting all services
5. To use systemd as a service manager, use the command "sudo systemctl" to start, stop, restart other daemon services. You can also enabled/disabled a service to define whether it shall start automatically at BOOT time.

## SSH

### What is SSH?

1. SSH stands for Secure Shell, it was first developed to secure the communication between two computers.
2. Computers communicate to each other via the Internet, using the "port" to send and receive data or information. However, everyone who has the port address can intercept the data you are tranmitting. Therefore, they develop a crypted method call SSH.

### How does SSH work?

1. The let's say computer A is sending a text message to computer B. Instead of sending the text directly, A will first put the text in a suitcase and locked (encrypted), and send it to B.
2. When B received the locked suitcase, he can not open it becasue he doesn't have the key. B will add another lock on the suitcase, and send it back to A to unlock A's lock.
3. When A receive back the suitcase, he will first check if there is a B's stamp on the suitcase with his lock on it. If yes, he unlocks his part and sents it to B again.
4. Finally, B receives again the suitcase and unlock the suitcase to access the text. This way, we can make sure that the delivery is encrypted during transmission.

reference: https://www.youtube.com/watch?v=qWKK_PNHnnA

### SSH Tunneling

1. First, just like the real world shipping, for computers there are ports with specific port numbers that they only recevie the data for the same port number.
2. Commonly used ports are port 80 (Hyper Text Transfer Protocal); port 22 (SSH), etc...
3. Since we already know that SSH is a secure connection to another computer, SSH tunnel allow you to smuggle and forward data from one port to another!
4. Ways of using SSH tunnel
    - Local Port Forwarding
        example:
        "ssh -L 8181:192.168.0.135:3389 user_name@192.168.0.135"
        - You are using port 8181 at the current machine and pass through ssh tunnel to connect the 3389 port at the server.
        - You could have been blocked by firewall if you try to connect to port 3389 directly.
    - Dynamic Port Forwarding
        example:
        "ssh -D 8181 user_name@192.168.0.135"
        - You use port 8181 and connect to SSH tunnel. Let's say you cannot visit certain websites because the port 80 is banned. You can change the proxy setting and chnage the port to 8181 to fix it.
    - Reverse Port Forwarding
        example:
        "ssh -R 8181:localhost:3389 user_name@192.168.0.135"
        - You use port 8181 and create a reverse tunnel that the server 192.168.0.135 can forward data to local.

reference: https://www.youtube.com/watch?v=AtuAdk4MwWw

## UFW

### What is UFW?

1. UFW stands for Uncomplicated Firewall. It is a program to set up firewall configurations.
2. You can use UFW to control all the ingoing and outgoing ports. You can even restrict certain visitors (with certain IP) has access to visit through certain ports.
### How to configure UFW?

1. "sudo ufw enable" to enable ufw at boot time
2. "sudo ufw status numbered" to show all ufw rules
3. "sudo ufw allow/deny (port number) to configure rules
4. "sudo ufw delete (port number) to delete rules

reference: https://www.youtube.com/watch?v=XtRXm4FFK7Q

## Cron

### What is Cron?

1. Cron or cron job is a service that can schedule commands or scripts to happen at specific intervals of time of in a specific frequency. For example, you want to back-up or clean the bin regualrly.
2. "crontab -e" to edit the cron job.

## TTY

### What is TTY?

1. TTY stands for TeleTypewriter, the name comes from old typewriters that used to telegraphs.
2. A tty is something that can accept input from a keyboard, or STDIN.

## For peer review

checklist: https://docs.google.com/document/d/1-BwCO0udUP7MhRh81Y681zz0BalXtKFtte_FHJc6G4s/edit

### How to change hostname

1. sudo hostnamectl set-hostname (new_hostname)
2. hostnamectl status

### How to create, modify, check, and delete user accounts

1. Create new user		:sudo adduser (new_usrname)
2. Create new group		:sudo groupadd (new_grpname)
3. Add user to a group		:sudo usermod -aG (grpname) (usrname)
4. Del user from a group	:sudo gpasswd -d (usrname) (grpname)
5. Check user pw rule		:sudo chage -l (usrname)
6. Check usrs in grp		:getent group (grpname)
7. Check all existing grps	:getent group
8. Check all existing usrs	:getent group users
9. Check grps of a usr		:groups
10. Check login usrs		:users / who
11. Delete a user		:sudo userdel (usrname) (use -r to remove all directories of the user)
12. Delete a group		:sudo groupdel (grpname)

### System services

1. Show service status      :sudo systemctl status (svc_name)
2. Start/Enable service     :sudo systemctl start/enable (svc_name)
3. Download/Install service :sudo apt install (svc_name)
4. Check download pkgs      :sudo dpkg -l | grep (svc_name)

### Firewall and SSH link

1. Check ufw status         :sudo ufw status numbered
2. Add rules                :sudo ufw allow/deny (port_number)
3. Delete rules             :sudo ufw delete (rule_number)
4. Access through SSH       :ssh (user_id)@127.0.0.1 -p (port_number)

## Bonus

### Lighttpd (web server)

1. Lighttpd, pronounced “lighty”, is an open-source web server optimized for speed-critical environments while remaining standards-compliant, secure, and flexible. It’s designed to be lightweight and have a small memory footprint, making it particularly suited for servers suffering from load problems and memory leaks.
2. Characteristics of Lighttpd
    1. Performance: Highly efficient and optimized for high-performance environments, with a small memory footprint.
    2. Simplicity: Simple to set up and configure, with a straightforward configuration file.
    3. Security: Built-in security features, including support for SSL/TLS, chroot support, and more.
    4. Flexibility: Supports a wide range of web technologies and applications, including FastCGI, SCGI, and HTTP proxy.
    5. Event-Driven: Uses an event-driven architecture to handle multiple connections efficiently.
    6. Compatibility: Compatible with most Unix-like operating systems and Windows.
3. Comparison to Similar Services

| Feature/Service   | Lighttpd                                    | Apache HTTP Server                      | Nginx                                 | Microsoft IIS                                        |
|-------------------|---------------------------------------------|-----------------------------------------|---------------------------------------|------------------------------------------------------|
| License           | BSD                                         | Apache License 2.0                      | BSD-like                              | Proprietary (Windows)                                |
| Open Source       | Yes                                         | Yes                                     | Yes                                   | No                                                   |
| Developer         | Jan Kneschke, community                     | Apache Software Foundation              | Igor Sysoev, NGINX Inc.               | Microsoft                                            |
| Initial Release   | 2003                                        | 1995                                    | 2004                                  | 1995                                                 |
| Performance       | High (event-driven)                         | Moderate to High (process/thread-based) | High (event-driven)                   | High                                                 |
| Memory Usage      | Low                                         | Moderate to High                        | Low                                   | High                                                 |
| Scalability       | Good                                        | Good                                    | Excellent                             | Good                                                 |
| Ease of Use       | Easy                                        | Moderate                                | Moderate                              | Easy (GUI-based)                                     |
| Configuration     | Simple (single config file)                 | Extensive (many modules and configs)    | Simple (single config file)           | GUI-based, extensive                                 |
| Security          | Strong                                      | Strong                                  | Strong                                | Strong                                               |
| Flexibility       | Moderate                                    | Very High (many modules)                | High                                  | High                                                 |
| Community Support | Moderate                                    | Very Strong                             | Strong                                | Moderate                                             |
| Use Cases         | High-performance, low-resource environments | General-purpose, highly customizable    | High-traffic websites, load balancing | Enterprise environments, Windows-centric deployments |


reference: https://webhostinggeeks.com/blog/what-is-lighttpd-web-server-and-how-does-it-work/

### MariaDB (database system)

- To check mariadb status: 
	- ```mysql -u root -p```
	- ```show databases;```
- Password: WPpassword

1. MariaDB is an open-source relational database management system (RDBMS) that is a fork of MySQL. After MySQL was acquired by Oracle, Maria aims to remain free and open-source while maintaining compatibility with MySQL, ensuring a drop-in replacement for MySQL users.
2. Comparison to Similar Services

| Feature/Service        | MariaDB                                  | MySQL                             | PostgreSQL                                  | SQLite                        |
|------------------------|------------------------------------------|-----------------------------------|---------------------------------------------|-------------------------------|
| License                | GPL, LGPL, BSD                           | GPL                               | PostgreSQL License                          | Public Domain                 |
| Open Source            | Yes                                      | Yes                               | Yes                                         | Yes                           |
| Developer              | MariaDB Foundation                       | Oracle Corporation                | PostgreSQL Global Dev. Group                | D. Richard Hipp               |
| Initial Release        | 2009                                     | 1995                              | 1996                                        | 2000                          |
| Default Storage Engine | InnoDB (Aria, MyRocks optional)          | InnoDB (MyISAM optional)          | Multiple (e.g., MVCC)                       | Single file storage           |
| SQL Compliance         | High (MySQL compatible)                  | High                              | Very High                                   | Moderate                      |
| Performance            | High, with various optimization features | High                              | High, especially for complex queries        | High for local usage          |
| Scalability            | High (Galera Cluster)                    | High                              | High (built-in replication, clustering)     | Limited to single application |
| Security               | Advanced (encryption, plugins)           | Standard (encryption, plugins)    | Advanced (built-in security features)       | Basic                         |
| Ease of Use            | Easy                                     | Easy                              | Moderate                                    | Very Easy                     |
| Community Support      | Strong                                   | Strong                            | Strong                                      | Moderate                      |
| Use Cases              | General-purpose, enterprise              | General-purpose, web applications | Advanced data applications, complex queries | Embedded systems, mobile apps |

### PHP (Server-side scripting language)

1. PHP originally stands for Personal Home Page, then becomes Hypertext Preprocessor, is a widely-used open-source servier-side scripting language especially suited for web development. First created in 1994, PHPH has evolved into a powerful tool for creating dynamic and interactive websites. It is embedded within HTML code and executed on the server, generating HTML which is then sent to the client.
2. Pros and Cons of PHP
    1. Pros:
    - Easy to learn and use, especially for beginners.
    - Extensive database support and integration.
    - Large community and vast resources.
    - Great performance with opcode caching.
    - Wide adoption and hosting support.
    2. Cons:
    - Historically criticized for security vulnerabilities if not properly managed.
    - Mixed reputation for code quality and readability.
    - Can be slower compared to some modern languages for certain tasks.
3. Comparison to Similar Services

| Feature/Service   | PHP                                                 | Python                                    | Ruby                                           | Node.js                              |
|-------------------|-----------------------------------------------------|-------------------------------------------|------------------------------------------------|--------------------------------------|
| License           | PHP License                                         | Python Software Foundation License        | MIT License                                    | MIT License                          |
| Open Source       | Yes                                                 | Yes                                       | Yes                                            | Yes                                  |
| Developer         | The PHP Group                                       | Python Software Foundation                | Yukihiro Matsumoto, community                  | Ryan Dahl, community                 |
| Initial Release   | 1995                                                | 1991                                      | 1995                                           | 2009                                 |
| Performance       | High with caching (e.g., OPCache)                   | Moderate to High                          | Moderate                                       | High                                 |
| Ease of Use       | Easy                                                | Easy to Moderate                          | Easy to Moderate                               | Moderate                             |
| Syntax            | C-like, embedded in HTML                            | Clear, readable                           | Elegant, concise                               | JavaScript-like                      |
| Scalability       | Good                                                | Good                                      | Good                                           | Excellent                            |
| Community Support | Very Strong                                         | Very Strong                               | Strong                                         | Strong                               |
| Frameworks        | Laravel, Symfony, CodeIgniter                       | Django, Flask                             | Ruby on Rails, Sinatra                         | Express, Koa                         |
| Use Cases         | Web development, dynamic web pages                  | Web development, data analysis, scripting | Web development, rapid prototyping             | Real-time applications, web services |
| Concurrency       | Limited by default, improved with tools like Swoole | Limited, improved with asyncio            | Limited by default, improved with EventMachine | Excellent with non-blocking I/O      |
| Hosting Support   | Widely supported                                    | Widely supported                          | Supported                                      | Supported                            |

### WordPress (Content Management system CMS)

- To check WordPress config ```/var/www/html/wp-config.php```
- Password: same as intra42
- username: tsuchen

1. WordPress is a free and open-source content management system (CMS) that is the most popular platform for creating websites and blogs.
2. Pros and Cons of WordPress
    1. Pros:
    - Highly customizable with themes and plugins.
    - Large community and extensive support resources.
    - SEO-friendly out of the box.
    - User-friendly interface, ideal for non-developers.
    - Regularly updated with new features and security patches.
    2. Cons:
    - Can be vulnerable to security issues if not properly managed.
    - Performance can be affected by poorly coded plugins or themes.
    - Can become complex and bloated with excessive plugins.
    - Requires regular maintenance and updates.
    - Limited scalability for extremely high-traffic websites without additional optimization.
3. Comparison to Similar Services

| Feature/Service   | WordPress                                     | Joomla                                        | Drupal                                   | Wix                                  | Squarespace                                  |
|-------------------|-----------------------------------------------|-----------------------------------------------|------------------------------------------|--------------------------------------|----------------------------------------------|
| License           | GPL                                           | GPL                                           | GPL                                      | Proprietary                          | Proprietary                                  |
| Open Source       | Yes                                           | Yes                                           | Yes                                      | No                                   | No                                           |
| Developer         | WordPress Foundation                          | Open Source Matters, Inc.                     | Drupal Association                       | Wix.com Ltd.                         | Squarespace, Inc.                            |
| Initial Release   | 2003                                          | 2005                                          | 2001                                     | 2006                                 | 2004                                         |
| Ease of Use       | Very Easy                                     | Moderate                                      | Difficult                                | Very Easy                            | Very Easy                                    |
| Customizability   | High (Themes, Plugins)                        | High (Extensions, Modules)                    | Very High (Modules, Custom Code)         | Moderate (Templates, Apps)           | Moderate (Templates, Extensions)             |
| Performance       | Moderate to High (with optimization)          | Moderate to High (with optimization)          | High (Optimized for large sites)         | Moderate                             | Moderate                                     |
| Scalability       | Moderate                                      | Moderate to High                              | High                                     | Limited                              | Limited                                      |
| Security          | Good (with regular updates and plugins)       | Good (with proper configuration)              | Excellent (with proper configuration)    | Good                                 | Good                                         |
| Community Support | Very Strong                                   | Strong                                        | Strong                                   | Moderate                             | Moderate                                     |
| SEO Features      | Excellent (Built-in and plugins)              | Good                                          | Good                                     | Good                                 | Good                                         |
| Use Cases         | Blogs, business sites, e-commerce, portfolios | Business sites, e-commerce, social networking | Large, complex websites, community sites | Small business sites, personal blogs | Small business sites, portfolios, e-commerce |
| Hosting Support   | Widely supported                              | Widely supported                              | Widely supported                         | Proprietary hosting                  | Proprietary hosting                          |

### Additional service: Curl

1. Curl stands for client url. It is an useful service to download information from http via interactive terminal.
2. Examples:
	- weather: curl wttr.in/(city name) or (airport abbr.)
	- phase of moon: curl wttr.in/moon or curl wttr.in/Moon@2024-Jul-23
	- geolocation: curl ipinfo.io/8.8.8.8

### Additional service: telnet

1. Examples:
	- map: telnet mapascii.me (you can zoom in and out!!!)

## Final thougt about this project and bonus

When I was doing the project, I had a question of why the bonus was about creating a personal webpage WordPress? Then I realized that the website is basically how two computers communicate via the port of 80 (or http)! Building a website is to create a interface for other people to visite your computer in a user friendly and structured presentation!

Therefore, to conclude the objectives of this project (which are quite a lot..)

1. Learn what is Virtual Machine? How does it work? Why and when we use it?
2. Understand the necessary steps to set up a machine
    1. Disk partition
    2. file system
    3. choice of OS
3. System security
    1. what is SELinux and AppArmor
    2. what is SSH and how does it work?
    3. what is UFW (Firewall) and how does it work?
4. Admin and account management
    1. what is Super user?
    2. how to setup a "SAFE" password policty
5. How to use do scheduled jobs with "cron"
6. [Bonus] How to create a website on your machine and setup availabe ports to allow visitors to visit.
