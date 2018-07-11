package assignment4;


/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 This file estabalishes a connection to a client
*/
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.Inet4Address;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 This file estabalishes a connection to a server
*/

 public class client implements host {

 	private static final String DEFAULT_HOST;
	private static final int DEFAULT_PORT = 12323;
	
	/*
	 Get the local IPv4 address. 
	 */
	static {
		try {
			DEFAULT_HOST = Inet4Address.getLocalHost().getHostAddress();
		} catch (UnknownHostException e) {
			throw new RuntimeException("Failed to retrieve Ipv4 address");
		}
	}

	private Socket socket;
	
	private String h;
	
	private int port;
	
	public client(String host, int port) {
		this.h = host;
		this.port = port;
	}

	/*
	  Run the client. It connects to the server, uses the Diffie-Hellman algorithm to establish a secret key with the server, reads user input for a message, then encrypts the message and sends it to the server.
	 */
	public void run() throws IOException {
		connect();
		int privateKey = getPrivateKey();
		String plaintext = getUserInput();
		sendEncryptedMessage(plaintext, privateKey);
		socket.close();
	}
	
	/*
	  Connect to the server.
	 */
	private void connect() throws IOException {
		System.out.println("Connecting to " + h + ":" + port);
		socket = new Socket(h, port);
		System.out.println("Connected to " + socket.getRemoteSocketAddress());
	}
	
	private int getPrivateKey() throws IOException {
		diffieHellmanKeyDelivery creator = new diffieHellmanKeyDelivery(this, false);
		return creator.calculateKey();
	}
	
	/*
	  Reads the user input that will be used as the message sent to the server.
	 */
	private String getUserInput() {
		Scanner input = new Scanner(System.in);
		try {
			String message = "";
			System.out.println("Please enter a message: ");
			do {
				message = input.nextLine();
			} while (message.length() < 1);
			return message;
		} finally {
			input.close();
		}
	}
	
	/*
	  Encrypts the plaintext message and sends it to the server.
	 */
	private void sendEncryptedMessage(String plaintext, int privateKey) throws IOException {
		encryption scheme = new encryption(privateKey);
		String cipher = scheme.encrypt(plaintext);
		printMessage(cipher);
		sendMessage(cipher);
	}
	
	/*
	  Print the encrypted message.
	 */
	private void printMessage(String cipher) {
		System.out.println("\nSending encrypted message:\n" + cipher + "\n");
	}
	
	/*
	  Sends a message to the server.
	 */
	public void sendMessage(String message) throws IOException {
		OutputStream os = socket.getOutputStream();
		DataOutputStream dos = new DataOutputStream(os);
		dos.writeUTF(message);
	}
	
	
	/*
	  Read the message from the server.
	 */
	public String readMessage() throws IOException {
		InputStream is = socket.getInputStream();
		DataInputStream dis = new DataInputStream(is);
		return dis.readUTF();
	}
	
	/*
	  Retrieve the host from the args.
	 */
	private static String getHostFromArgs(String[] args) {
		if (args.length > 0) {
			return args[0];
		} else {
			return DEFAULT_HOST;
		}
	}
	
	/*
	  Retrieve the port number from the args.
	 */
	private static int getPortFromArgs(String[] args) {
		if (args.length > 1) {
			try {
				return Integer.parseInt(args[2]);
			} catch (NumberFormatException e) {
				return DEFAULT_PORT;
			}
		} else {
			return DEFAULT_PORT;
		}
	}
	
	public static void main(String args[]) {
		String host = getHostFromArgs(args);
		int port = getPortFromArgs(args);
		client c =  new client(host, port);
		try {
			c.run();			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

 }