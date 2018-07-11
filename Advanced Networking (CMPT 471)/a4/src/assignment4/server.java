package assignment4;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Inet4Address;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 This file estabalishes a connection to a client
*/

public class server implements host {

	private static final int DEFAULT_PORT = 12323;
	
	private ServerSocket serverSocket;
	
	private Socket socket;
	
	/*
	  Open a new connection on the default port.
	 */
	public server() throws IOException {
		new server(DEFAULT_PORT);
	}

	/*
	  Open a new connection on the specified port.
	 */
	public server(int port) throws IOException {
		serverSocket = new ServerSocket(port);
	}

	/*
	  Run the server.
	 */
	public void run() throws IOException {
		while (true) {	
			acceptConnection();
			int privateKey = getPrivateKey();
			String cipher = readMessage();
			String decryption = decryptMessage(cipher, privateKey);
			printMessages(cipher, decryption);
			socket.close();
		}
	}

	/*
	  Wait for a connection to the server socket from the client and accept it.
	 */
	private void acceptConnection() throws IOException {
		System.out.println(getInetAddress() + " Listening on port " + serverSocket.getLocalPort() + "...");
		this.socket = serverSocket.accept();
		System.out.println("Accepted connection from " + socket.getRemoteSocketAddress());
	}
	
	
	private int getPrivateKey() throws IOException {
		diffieHellmanKeyDelivery creator = new diffieHellmanKeyDelivery(this, false);
		return creator.calculateKey();
	}
	
	/*
	  Get the local IPv4 address.
	 */
	private String getInetAddress() {
		try {
			return Inet4Address.getLocalHost().getHostAddress();
		} catch (UnknownHostException e) {
			return "";
		}
	}
	
	/*
	  Read the input from the client and prints the data in UTF format.
	 */
	public String readMessage() throws IOException {
		DataInputStream inputStream = new DataInputStream(socket.getInputStream());
		return inputStream.readUTF();
	}
	
	/*
	  Decrypts the cipher sent by the client. 
	 */
	private String decryptMessage(String cipher, int privateKey) {
		encryption scheme = new encryption(privateKey);
		return scheme.decrypt(cipher);
	}
	
	/*
	  Print the encrypted and decrypted messages.
	 */
	private void printMessages(String cipher, String decryption) {
		System.out.println("\nReceived encrypted message:\n" + cipher + "\n");
		System.out.println("Decrypted:\n" + decryption + "\n");
	}
	
	/*
	  Sends a message to the client.
	 */
	public void sendMessage(String message) throws IOException {
		DataOutputStream outputStream = new DataOutputStream(socket.getOutputStream());
        outputStream.writeUTF(message);
	}
	
	/*
	  Retrieve the port from the args array.
	 */
	private static int getPortFromArgs(String[] args) {
		if (args.length > 0) {
			try {
				return Integer.parseInt(args[0]);
			} catch (NumberFormatException e) {
				return DEFAULT_PORT;
			}
		}
		return DEFAULT_PORT;
	}
	
	public static void main(String[] args) {
		int port = getPortFromArgs(args);
		try {
			server s = new server(port);
			s.run();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}


