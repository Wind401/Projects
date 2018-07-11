package assignment4;

import java.util.Arrays;

/*
 Name: Siddharth Chugh
 Student Number: 301236542
 CMPT 471 Assignment 4
 Transposition Encrytion Scheme 
*/

public class TranspositionScheme {

	/*
	 Empty Spaces in matrix causes problems.
	 Therefore, it needs to be filled with ~
	*/
	private static final char MATRIX_FILLER_CHAR = '~';
	
	/*
	 Key required to encrypt and decrypt the message.
	
	*/
	private final int[] Key;
	
	public TranspositionScheme(int[] Key) {
		this.Key = Key;
	}
	
	/*
	 Arranges the text into a matrix, then transposes the matrix using the key.
	*/

	public String encrypt(String text) {
		char[][] matrix = createEncryptedMatrix(text);
		
		return getTextFromMatrix(matrix);
	}

	private char[][] createEncryptedMatrix(String text)
	{
		int numberOfColumns = Key.length;
		int numberOfRows = getNumberOfRows(text);

		char[][] matrix = buildMatrix(numberOfRows, numberOfColumns, text);

		char[][] transposedMatrix = new char[matrix[0].length][matrix.length];
		int numberOfRowsTransposedMatrix = matrix.length;
		int i = 0;
		for (int col : Key) {
			for (int row = 0; row < numberOfRowsTransposedMatrix; row++) {
				transposedMatrix[i][row] = matrix[row][col];
			}
			i++;
		}
		return transposedMatrix;
	}
	
	/*
	  Build the matrix with the specified number of rows and columns.
	 */
	private char[][] buildMatrix(int rows, int columns, String text) {
		char[][] matrix = new char[rows][columns];
		
		for (char[] row : matrix) {
			Arrays.fill(row, MATRIX_FILLER_CHAR);
		}
		
		char[] chars = text.toCharArray();
		for (int i = 0; i < text.length(); i++) {
			matrix[i / columns][i % columns] = chars[i];
		}

		return matrix;
	}
	
	/*
	  Calculate the number of rows needed for the matrix, given the length of the 
	  text and the length of the transposition key.
	 */
	private int getNumberOfRows(String text) {
		int fullRows = text.length() / Key.length;
		int remainder = text.length() % Key.length;
		return (remainder == 0) ? fullRows : ++fullRows;
	}

	/*
	  Iterates over the matrix left to right and top to bottom, returning the 
	  text.
	 */
	private String getTextFromMatrix(char[][] matrix) {
		String text = "";
		for (char[] row : matrix) {
			for (char c : row) {
				if (c != Character.MIN_VALUE) text += c;
			}
		}
		return text;
	}
	
	/*
	  Reverses the process of {@link #encrypt(String)}, decrpyting the ciphertext.
	 */
	public String decrypt(String ciphertext) {
		char[][] matrix = createDecryptedMatrix(ciphertext);

		return getTextFromMatrix(matrix);
	}

	private char[][] createDecryptedMatrix(String ciphertext)
	{
		int numberOfRows = Key.length;
		int numberOfColumns = getNumberOfRows(ciphertext);

		char[][] matrix = buildMatrix(numberOfRows, numberOfColumns, ciphertext);

		char[][] detransposedMatrix = new char[matrix[0].length][matrix.length];
		int numberOfRowsDetransposedMatrix = matrix.length;
		int numberOfColumnsDetransposedMatrix = matrix[0].length;
		for (int row = 0; row < numberOfRowsDetransposedMatrix; row++) {
			for (int col = 0; col < numberOfColumnsDetransposedMatrix; col++) {
				detransposedMatrix[col][Key[row]] = matrix[row][col];
			}
		}
		for (int col = detransposedMatrix[0].length - 1; col > 0; col--) {
			if (detransposedMatrix[detransposedMatrix.length - 1][col] == MATRIX_FILLER_CHAR) {
				detransposedMatrix[detransposedMatrix.length - 1][col] = Character.MIN_VALUE;
			} 
			else {

			}
		}
		return detransposedMatrix;

	}
	
}