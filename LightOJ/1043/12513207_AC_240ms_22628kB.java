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
	  double ab, ac, bc, r;
	  ab = sc.nextDouble();
	  ac = sc.nextDouble();
	  bc = sc.nextDouble();
	  r = sc.nextDouble();
	  
	  double lo = 0, hi = Math.max(ab,  Math.max(ac, bc));
	  r = r/(r+1);
	  for(int i=0; i<100; i++) {
	    double mid = (lo+hi)/2.0;
	    double x = mid/ab;
	    if( x*x>r ) hi = mid;
	    else lo = mid;
	  }
	  pf.printf("Case %d: %.8f\n", ++caseno, lo);
      cases--;
	}
	sc.close();
	pf.close();
  }
}
