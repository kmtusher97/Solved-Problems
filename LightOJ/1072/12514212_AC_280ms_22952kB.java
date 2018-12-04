/*
 * @author user
 */

import java.lang.Math;
import java.util.Scanner;
import java.io.PrintWriter;

public class Main {
  public static void main( String[] args ) {
	Scanner sc = new Scanner( System.in );
	PrintWriter pf = new PrintWriter( System.out );
	int cases = sc.nextInt(), caseno = 0;
	while( cases>0 ) {
	    double R = sc.nextDouble(), r, x;
	    int n = sc.nextInt();
	    x = (2*Math.PI)/(double)n;
	    x /= 2.0;
	    x = Math.sin(x);
	    r = (x*R)/(1+x);
	    pf.printf("Case %d: %.8f\n", ++caseno, r);
		cases--;
	}
	sc.close();
	pf.close();
  }
}
