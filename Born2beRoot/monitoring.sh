#!/bin/bash

ARCH=$(uname -a)
PCPU=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
VCPU=$(grep "^processor" /proc/cpuinfo | uniq | wc -l)
RAM_TOTAL=$(free -h | awk '$1 == "Mem:" {print $2}')
RAM_USED=$(free -h | awk '$1 == "Mem:" {print $3}')
RAM_PERC=$(free -k | awk '$1 == "Mem:" {printf("%.2f%%"), $3/$2*100}')
DISK_TOTAL=$(df -h --total | awk '$1 == "total" {print $2}')
DISK_USED=$(df -h --total | awk '$1 == "total" {print $3}')
DISK_PERC=$(df -k --total | awk '$1 == "total" {print $5}')
CPU_LOAD=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')
LAST_BOOT=$(who -b | awk '{print $3 " " $4}')
LVM=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
TCP_COUNT=$(grep TCP /proc/net/sockstat | awk '{print $3}')
USER_LOG=$(who | wc -l)
IP_ADDR=$(hostname -I | awk '{print $1}')
MAC_ADDR=$(ip link show | grep ether | awk '{print $2}')
SUDO_LOG=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "	
	---------------------------------------------------
	Architecture	: $ARCH
	Physical CPUs	: $PCPU
	Virtual CPUs	: $VCPU
	Memory Usage	: $RAM_USED/$RAM_TOTAL ($RAM_PERC)
	Disk Usage	: $DISK_USED/$DISK_TOTAL ($DISK_PERC)
	CPU Load	: $CPU_LOAD
	Last Boot	: $LAST_BOOT
	LVM Use		: $LVM
	TCP Connections	: $TCP_COUNT ESTABLISHED
	User Logged	: $USER_LOG
	Network		: IP $IP_ADDR ($MAC_ADDR)
	Sudo		: $SUDO_LOG COMMANDS USED
	---------------------------------------------------"
