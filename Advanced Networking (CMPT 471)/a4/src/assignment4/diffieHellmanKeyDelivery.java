package assignment4;

import java.io.IOException;
import java.math.BigInteger;
import java.util.Random;

/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 This file implements a diffieHellamn key delivery protocol
*/

 public class diffieHellmanKeyDelivery {

 	private static final int PRIVATE_NUMBER_MAX_VALUE = 10000;
	
	private BigInteger n;
	private BigInteger q;
	
	private int privateNumber;
	
	/*
	 Either the client or the server 
	 */
	private host h;

	private static final int MIN_PRIME_VALUE = 1001;
	private static final int PRIME_VALUE_RANGE = 10000;

	
	/*
	  Flag specifying whether the host is a client or a server. 
	  Implementation details can be found in client.java and server.java
	 */
	private boolean isClient;

	public diffieHellmanKeyDelivery(host h, boolean isClient) {
		this.isClient = isClient;
		this.h = h;
		initializePrivateNumber();
	}

	private void initializePrivateNumber() {
		Random rand = new Random();
		privateNumber = rand.nextInt(PRIVATE_NUMBER_MAX_VALUE) + 2;
	}

	/*
	  Generates a prime number within the range of [1001, 11001].
	 */
	public static int generatePrimeNumber() {
		int candidate = generateCandidateNumber();
		while (!isPrime(candidate)) {
			candidate++;
		}
		return candidate;
	}
	
	private static int generateCandidateNumber() {
		Random rand = new Random();
		return rand.nextInt(PRIME_VALUE_RANGE) + MIN_PRIME_VALUE;
	}
	
	private static boolean isPrime(int n) {
	    if (n % 2 == 0) return n == 2;
	    if (n % 3 == 0) return n == 3;
	    int step = 4, m = (int)Math.sqrt(n) + 1;
	    for(int i = 5; i < m; step = 6-step, i += step) {
	        if (n % i == 0) {
	            return false;
	        }
	    }
	    return true;
	}

	/*
	  Main algorithm performing the diffie-hellman encryption. 
	 */
	public int calculateKey() throws IOException {
		sharePublicPrimeNumbers();
		calculateAndSendMyPublicNumber();
		BigInteger otherPublicNumber = readOtherPublicNumber();
		
		return calculatePrivateKey(otherPublicNumber);
	}
	
	/*
	  Share the public primes. If the host is the client, it sends a message to the server containing the primes. If the host is the server, it receives the primes from the client.
	 */
	private void sharePublicPrimeNumbers() throws IOException {
		if (isClient) {
			n = BigInteger.valueOf(generatePrimeNumber());
			q = BigInteger.valueOf(generatePrimeNumber());
			h.sendMessage(n.toString() + " " + q.toString());
		} else {
			String publicNumbers = h.readMessage();
			n = new BigInteger(publicNumbers.split(" ")[0]);
			q = new BigInteger(publicNumbers.split(" ")[1]);
		}
	}
	
	/*
	 Calculates the public number for the host and sends it to the other host.
	 */
	private void calculateAndSendMyPublicNumber() throws IOException {
		BigInteger myPublicNumber = calculatePublicNumber();
		h.sendMessage(myPublicNumber.toString());
	}
	
		private BigInteger calculatePublicNumber() {
		return n.pow(privateNumber).mod(q);
	}
	
	/*
	  Read the public number sent from the other host.
	 */
	private BigInteger readOtherPublicNumber() throws IOException {
		String message = h.readMessage();
		return new BigInteger(message);
	}
	
	private int calculatePrivateKey(BigInteger publicKey) {
		return publicKey.pow(privateNumber).mod(q).intValue();
	}

 }
