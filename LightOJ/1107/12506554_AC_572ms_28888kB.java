/*
 * 
 * @author User
 *
 */

//import java.io.*;
import java.util.Scanner;

public class Main {
  public static void main( String[] args ) {
	Scanner sc = new Scanner( System.in );
	//PrintWriter pf = new PrintWriter( System.out );
	
	int cases = sc.nextInt();
	for(int cs=1; cs<=cases; cs++) {
	  int[] a = new int[5];
      for(int i=1; i<=4; i++) {
    	a[i] = sc.nextInt();
      }
      int n = sc.nextInt();
      System.out.printf("Case %d:\n", cs);
      while( n>0 ) {
    	int x, y;
    	x = sc.nextInt();
    	y = sc.nextInt();
    	if( (x>=a[1] && x<=a[3]) && (y>=a[2] && y<=a[4]) ) {
    	  System.out.println("Yes");
    	}
    	else {
    	  System.out.println("No");
    	}
    	n--;
      }
	}
	sc.close();
	//pf.close();
  }
}
