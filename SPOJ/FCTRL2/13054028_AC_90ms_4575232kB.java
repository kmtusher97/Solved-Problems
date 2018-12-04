/*
 * @tshr
 */

import java.util.Scanner;
import java.math.BigInteger;

public class Main { 
	static BigInteger[] ff = new BigInteger[102];
	
	public static void precal() {
		ff[0] = new BigInteger("1");
		for(int i=1; i<102; i++) {
			ff[i] = ff[i-1].multiply(BigInteger.valueOf(i));
		}
	}
	public static void main( String[] args ) {
		Scanner sc = new Scanner( System.in );
		precal();
		int cases = sc.nextInt();
		while( cases-->0 ) {
			int n = sc.nextInt();
			System.out.println(ff[n]);
		}
	}
}