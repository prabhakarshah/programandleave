/*
*Problem statement
*To find length of connected cells of 1s in a matrix of 0s and 1s
*/
public class RecursionDfsMatrixPath {
  	static int recVal=0;

	public static void main(String[] args) {
	
		int[][] array = { { 0, 1, 1 }, { 1, 1, 0 }, { 0, 0, 1 } };
		System.out.println(recur(array, 0, 0, 0));
  }
	private static int recur(int[][] array, int i, int j, int v) {
        if(recVal<v)
        	recVal = v;
		if (isLeftPossible(array, i, j)) {
			recur(array, i-1, j, v+1);
		}
		if (isRightPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}
		if (isUpPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}
		if (isDownPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}
		if (isLUPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}
		if (isLDPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}
		if (isRUPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}
		if (isRDPossible(array, i, j)) {
			recur(array, i, j+1, v+1);
		}

		return recVal;
	}

	private static boolean isLeftPossible(int[][] array, int i, int j) {
		return (((j-1)>=0) && i>=0 && i<array.length && (array[i][j-1]==1));
	}
	private static boolean isRightPossible(int[][] array, int i, int j) {
		return (((j+1)<array.length)&& i>=0 && i<array.length && array[i][j+1]==1);
	}
	private static boolean isUpPossible(int[][] array, int i, int j) {
		return ((i-1>=0)&& array[i-1][j]==1);
	}
	private static boolean isDownPossible(int[][] array, int i, int j) {
		return ((i+1<array.length)&& j>=0 && j<array.length&& array[i+1][j]==1);
	}
	private static boolean isLUPossible(int[][] array, int i, int j) {
		return ((i-1>=0)&& (j-1>=0) &&  array[i-1][j-1]==1);
	}
	private static boolean isLDPossible(int[][] array, int i, int j) {
		return ((i-1>=0)&& (j+1)<array.length && array[i-1][j+1]==1);
	}
	private static boolean isRUPossible(int[][] array, int i, int j) {
		return (((i+1)<array.length)&& ((j-1)>=0) && (j-1)<array.length && (i+1)>=0 && array[i+1][j-1]==1);
	}
	private static boolean isRDPossible(int[][] array, int i, int j) {
		return ((j+1<array.length)&& (i+1<array.length) && array[i+1][j+1]==1);
	}
}
