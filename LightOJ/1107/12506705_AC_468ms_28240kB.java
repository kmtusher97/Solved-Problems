/*
 * @author user
 */

import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
  public static void main( String[] args ) {
	Scanner sc = new Scanner( System.in );
	PrintWriter pf = new PrintWriter( System.out );
	int cases, n;
	int[] a = new int[5];
	cases = sc.nextInt();
	for(int cs=1; cs<=cases; cs++) {
      for(int i=1; i<=4; i++) {
    	a[i] = sc.nextInt();
      }
      n = sc.nextInt();
      pf.printf("Case %d:\n", cs);
      while( n>0 ) {
    	int x, y;
    	x = sc.nextInt();
    	y = sc.nextInt();
    	if( (x>=a[1] && x<=a[3]) && (y>=a[2] && y<=a[4]) ) {
    	  pf.println("Yes");
    	}
    	else {
    	  pf.println("No");
    	}
    	n--;
      }
	}
	sc.close();
	pf.close();
  }
}
