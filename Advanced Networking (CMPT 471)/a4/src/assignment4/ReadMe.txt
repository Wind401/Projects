Name: Siddharth Chugh
Student Number: 301236542

CMPT 471 Assignment4

How to execute web services on the virtual connection:

Server.java

javac Server.java "Server"

It would run the server and if there any messages, it would show the encryted message and then decrypt it.

Client.java

javac Client.java "Client"

It can be run on a client machine and can be connected to server. 
It has the ability to send messages to server in encryted format.


encryption.java

It incorporates a two tier security on the messages exchanged between server and client.
It first uses substitution on plaintext and then uses transposition to return the cipher.
To decrypt is just does the opposite.
