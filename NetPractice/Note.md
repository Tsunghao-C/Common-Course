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
