#!/bin/bash
#Name : Siddharth Chugh
# Student Number: 301236542


# ICMP Codes
_ICMP_CODE_UNREACHABLE=3
_ICMP_CODE_REDIRECT=5

# Temporary file for displaying routing path
_temp_File="./temp_rr.txt"

# Hosts
_UnreachableHost="172.22.1.12"
_router="172.17.1.2"
_redirectHost="172.16.1.9"
_IPV6Host="fdd0:8184:d967:18:250:56ff:fe85:d1d8"


# Enables user to view output clearly
_formatter()
{
 printf "\n"
 echo "***********************************************************************************************************************************************************************"
 printf "\n"
}



# Pings host
_pingHost()
{
	sleep 1
	for i in {0..3}; do
    
    #Supressing the Ouput
		ping -c 1 -w 1 "$_UnreachableHost" > /dev/null 2>&1
	done
}

# Capture an ICMP Destination Unreachable message by sending pings
# to an unreachable host, and listening for ICMP unreachable messages
# via tcpdump.
_captureUnreachableDestination()
{
	_formatter
	echo "Part 1"
	echo "ICMP Destination Unreachable Message:"

# Allowing the function to run in background
	_pingHost &

	tcpdump -vvni eth1 -c 1 -e icmp[icmptype] == $_ICMP_CODE_UNREACHABLE

	_formatter
}

_pingHostAndWriteToFile()

{
 sleep 2
 _RR=$(ping -c 1 -w 1 -R "$_redirectHost")
 echo -n "$_Routing_Path" > $_temp_File
}

_displayRoutingCaches()

{
 printf "\n"
 echo "Before Redirect:"
 printf "\n"
 echo -n "$1"
 printf "\n"
 echo "After Redirect:"
 printf "\n"
 route -C
 printf "\n"
}


_displayRoutingPath()

{
 echo ""
 cat $_temp_File | grep -A 10 RR | egrep -v "statistics|packets"
 rm $_temp_File
 echo ""
}


_captureRedirect()

{
 _formatter
 echo "Part 2"
 echo "ICMP Destination Redirect Message:"	

# Setup the routing table for redirects
 ip route flush cache

 #Supressing the Ouput
 route del default gw "$_router" > /dev/null 2>&1
 route add default gw "$_router"
 
 local oldCache=$(route -C)
 
 # Allowing the function to run in background
 _pingHostAndWriteToFile &


 tcpdump -vvnni eth1 -c 1 -e icmp[icmptype] == $_ICMP_CODE_REDIRECT


 _displayRoutingCaches "$oldCache"


 _displayRoutingPath "$_Routing_Path"


 route del default gw "$_router"
 
  _formatter
}

_tracepath6Wrapper()
{
  sleep 1
  #Supressing the Ouput
  tracepath6 "$_IPV6Host" > /dev/null 2>&1
}


_captureDatagrams()
{
	_formatter

	echo "Part 3"
  echo "Capturing Datagrams"	

   #IPV6 Datagrams
  _tracepath6Wrapper &
  tcpdump -ni eth1 -c 1 ip6
  
  #IPV4 Datagarm encapsulated in IPV6
  _tracepath6Wrapper &
  tcpdump -ni eth1 -c 1 ip[9]==41
   _formatter
}


_captureUnreachableDestination
_captureRedirect
_captureDatagrams