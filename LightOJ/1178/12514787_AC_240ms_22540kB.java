/*
 * @author user
 */

import java.lang.Math;
import java.util.Scanner;
import java.io.PrintWriter;

public class Main {
  static final double eps = 1e-7;
  public static void main( String[] args ) {
	Scanner sc = new Scanner( System.in );
	PrintWriter pf = new PrintWriter( System.out );
	int cases = sc.nextInt(), caseno = 0;
	while( cases>0 ) {
      double a, b, c, d, A, s, aa;
      a = sc.nextDouble();
      b = sc.nextDouble();
      c = sc.nextDouble();
      d = sc.nextDouble();
    
      aa = Math.abs(a-c);
      s = (aa + b + d)/2.0;
      A = Math.sqrt( s*(s-aa)*(s-b)*(s-d) );
      aa = (2*A)/aa;
      A += (aa*Math.min(a, c));
      pf.printf("Case %d: %.7f\n", ++caseno, A);
	  cases--;
	}
	sc.close();
	pf.close();
  }
}
