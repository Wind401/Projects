package assignemnt4;

import java.io.IOException;

/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 This file implements a host interface to be used by encryption services to deliever messages.
*/

 public class host {

 	/*
	  Sends a message from one host to the other. 
	 */
	void sendMessage(String message) throws IOException;
	
	/*
	  Reads a message from the other host. 
	 */
	String readMessage() throws IOException;
	
	/*
	  Run the client or server.
	 */
	void run() throws IOException;
 }