# Notes for Net Pratices

## TCP IP Addressing

### IP (Internet Protocal)
1. IP address is like a phone number to each terminal (devices). In order to communicate to a target device, you need to have the target's IP address.
2. Three key things for IP address
    1. IP address       ex. 192.168.1.204
    2. Net Mask         ex. 255.255.255.0
    3. Default Gateway  ex. 192.168.1.1
3. If a device is connected to a router, **It is the router to assign IP addresses to the connected devices.**
4. **Octets** This from like 192.168.1.1 is called an octet.
5. The Mask number of 255 means it is locked and should never change. On the contrary, 0 in mask means it is change-able (assign-able).
```
    example: 
        IP      192.168.1.  204
        Mask    255.255.255.0
                Network Portion
                            Host Portion
```
6. Each device connecting to a router is call a **HOST**
7. Imagine you are trying to communicate to another Host, and you have its number (IP address).
    - if the Network Portion is the same: means you are neighbors, you are connected to the same router.
    - if the Network Portion is not the same: you need to turn to router (**Gateway**) to complete the communication.
8. How many hosts are available under a router?
    - The answer is 253, because the first two and last host number are reserved for:
        1. Netwwork address: 192.168.1.0
        2. Broadcast address: 192.168.1.255
        3. Default address: 192.168.1.1

### We ran OUT of IP Addresses -> Subnetting

|Class  |Range                       |Subnet Mask   |Remark|
|-------|----------------------------|--------------|------|
|A      |1.0.0.0 - 126.255.255.255   |255.0.0.0     |For big organizations. You can assign 2^24 subnet hosts for each network.|
|B      |128.0.0.0 - 191.255.0.0     |255.255.0.0   |Each network can assign 2^16 hosts.|
|C      |192.0.0.0 - 223.255.255.0   |255.255.255.0 |Commonly used small sized network.|
|D      |224.0.0.0 - 239.255.255.255 |              |Reserved for multi-cast networking. Cannot use!|
|E      |240.0.0.0 - 255.255.255.255 |              |Reserved for military and FBI, CIA. Cannot use!|

- The missing IP address starting with 127.0.0.0 to 127.255.255.255 are reserved for your current operation machine called as **Loop back address**.
- Try ```ping 127.0.0.1``` in the terminal.

### RFC 1918 bandaid -> Private IP Address

1. Due to the poor IP address allocation from IANA, soon the IP addresses are not enough for everybody.
2. To resolve this issue, here comes the private IP address. The routers assign **Private** IP addresses to hosts that are connected. In side the regional network, we use private IP address to distinguish each other. Only when we try to access to outer network, we use the **Public IP Address** (usually the IP of the router) to communicate.
#### Subcategory of Private IP address

|Class  |Range      |Subnet Mask    |
|-------|-----------|---------------|
|A      |10.0.0.0 - 10.255.255.255|255.0.0.0    |
|B      |172.16.0.0 - 172.31.255.255|255.255.0.0|
|C      |192.168.0.0 - 192.168.255.255|255.255.255.0|

- This helps explain why we always see the IPv4 starting with 192.168.0, a Class C IP address range.
- However, the private IP addresses are not publically routable. We need to use NAT (Network Address Translation) to connect to the internet.
#### NAT (Network Address Translation)
1. We need a **Public** IP address to connect to the Internet. Public IP address is provided by ISP (Internet Service Provider) like AT&T, Orange, etc.
2. Every home devices connecting to your WIFI router use the same public IP address to connect to the Internet! And when theInternet send a package back to the router, the router will forward to the device that claimed for it.
#### IPv4 and IPv6
1. Traditional IP addresses are IPv4, which consists of for numbers between 0 to 255 and are separated by three dots.
``` IPv4: 192.168.1.1 ```
2. Even using Public and Private IP addresses, the public IP addresses are still not enough. Imagine everyone has a cell phone that needs to connect to the internet directly!
3. Therefore, later there comes a more complicated IP address standard call IPv6, that has 2^128 combinations.
``` IPv6: 2001:db8:3333:4444:5555:6666:7777:8888 ```
4. So nowadays, all smart phones has a unique IPv6 addresses in order to access internet independently.

1 octets (8 bits) is 1 byte.

### What is a Subnet Mask

1. A subnet mask is a 32-bit number created by setting host bits to all 0s (host portion) and setting network bits to all 1s (Network portion).
2. It is more intuitive to understand how it works in binary presentation:
```
IP  : 11000000.10101000.00100000.00000101 | 192.168.32 .5
Mask: 11111111.11111111.11111111.00000000 | 255.255.255.0

available hosts: 2^8 - 2 = 254
```
3. Lets say, we actually need to accomodate 500 hosts in this network. What do we do? We need to borrow a 1 from the network to expand the numbers for host.

```
IP  : 11000000.10101000.00100000.00000101 | 192.168.32 .5
Mask: 11111111.11111111.11111110.00000000 | 255.255.254.0

available hosts: 2^9 - 2 = 510
```

### How to create your home network

Question: How to create 5 networks?

1. Calculate how many host bits you need to hack
    - to create 5 networks, you need 3 bits (2^3 = 8)
2. Hack the host bits
    - had 3 bits from the host bits, the subnet Mask will be like:
```
Mask: 11111111.11111111.11111111.11100000 | 255.255.255.224
```
3. Find the increment
    - since we uses 3 bits, the increment will be 2^(8 - 3) = 32
4. Create your networks
```
    1. 192.168.1.0   - 192.168.1.31
    2. 192.168.1.32  - 192.168.1.63
    3. 192.168.1.64  - 192.168.1.95
    4. 192.168.1.96  - 192.168.1.127
    5. 192.168.1.128 - 192.168.1.159
```

### How to subnetting based on number of hosts needed

Question: How to create subnetting if there are 5 routers and each routers need to assign 20 hosts?

your network: 142.2.0.0/16

16 means the number of subnet masks, which is equal to 

Mask: 11111111.11111111.00000000.00000000 | 255.255.0.0

1. Use Nozferat2 to calculate how many host bits is needed

To assign 20 hosts, you need the 5 host bits
```
Nozferat : 128 64  32  16  8  4  2  1
Nozferat2: 256 128 64  32  16 8  4  2
                       Here
```
2. Save the host bits (from right to left)
    - The subnet will be like:
```
Mask: 11111111.11111111.11111111.11100000 | 255.255.255.224
3. Find the increment
    - The increment will be 2^5 = 32
4. Create your networks
```
    1. 142.2.0.0   - 142.2.0.31
    2. 142.2.0.32  - 142.2.0.63
    3. 142.2.0.64  - 142.2.0.95
    4. 142.2.0.96  - 142.2.0.127
    5. 142.2.0.128 - 142.2.0.159
```

So the final answer of all the networks:
    1. 142.2.0.0/27
    2. 142.2.0.32/27
    3. 142.2.0.64/27
    4. 142.2.0.96/27
    5. 142.2.0.128/27

And each network can have 32 - 2 = 30 usable IP addresses.

### Reverse subnetting

Question: How to get the following info by giving you an IP config?

```
example
IP  : 10101100.00010001.00010000.11111111 | 172.17.16.255
Mask: 11111111.11111111.11110000.00000000 | 255.255.240.0
Gway: 10101100.00010001.00000000.00000001 | 172.17.0.1
```

The increment is 16, the last "1" in the mask.
So the networks are:
    1. 172.17.0.0  - 172.17.15.255
    2. 172.17.16.0 - 172.17.31.255 <- In this range
    3. 172.17.32.0 - 172.17.47.255
    4. 172.17.48.0 - 172.17.63.255

Therefore, the answer will be:
    1. Network address      -> 172.17.0.0/20
    2. Broadcast address    -> 172.17.31.255 (the last IP in the range)
    3. Network range        -> 172.17.16.0 - 172.17.31.255

### Variable Length Subnet Masking (VLSM)

Question: Create 4 networks that has different host requirements:
    1. guest -> 10 hosts
    2. robots -> 57 hosts
    3. servers -> 26 hosts
    4. workers -> 117 hosts
    Public IP: 172.21.42.0/24

Total hosts = 10 + 57 + 26 + 117 = 210, smaller than maximum number 253 (256 -3) for a /24 mask.

**Always check for the largest host requirements first**

1. handle workers (117)
    1. the host bit needed is 7
    2. the mask would be: 255.255.255.128
    3. the increment is 128
    4. network range is 172.21.42.0 - 172.21.42.127
    5. network: 172.21.42.0/25
2. handle robots (57)
    1. the host bit needed is 6
    2. the mask would be: 255.255.255.192
    3. the increment is 64
    4. network range is 172.21.42.128 - 172.21.42.191
    5. network: 172.21.42.128/26
3. handle servers (26)
    1. the host bit needed is 5
    2. the mask would be: 255.255.255.224
    3. the increment is 32
    4. network range is 172.21.42.192 - 172.21.42.223
    5. network: 172.21.42.192/27
4. handle guest (10)
    1. the host bit needed is 4
    2. the mask would be: 255.255.255.240
    3. the increment is 16
    4. network range is 172.21.42.224 - 172.21.42.239
    5. network: 172.21.42.224/28
