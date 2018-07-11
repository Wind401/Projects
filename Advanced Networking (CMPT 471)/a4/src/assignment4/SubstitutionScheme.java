package assignment4;

/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 Substitution Encrytion Scheme 
*/

public class SubstitutionScheme {

	private static final int SMALLEST_CHAR_DECIMAL_VALUE = 32;
	
	/*
	 Key required to encrypt and decrypt the message.
	*/
	private final String Key;
	
	public SubstitutionScheme(String Key) {
		this.Key = Key;
	}
	
	/*
	  Encrypts the plaintext by substitution. 
	 */

	public String encrypt(String plaintext) {
		String cipher = "";
		for (char c : plaintext.toCharArray()) {
			cipher += Key.charAt((int) c - SMALLEST_CHAR_DECIMAL_VALUE);
		}
		
		return cipher;
	}
	
	/*
	 Decrypts the ciphertext by reversing the process of the encryption.
	 */
	public String decrypt(String ciphertext) {
		String text = "";
		for (char c : ciphertext.toCharArray()) {
			text += (char) (Key.indexOf((int) c) + SMALLEST_CHAR_DECIMAL_VALUE);
		}
		
		return text;
	}
}