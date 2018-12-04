/*
 * @author user
 */

import java.lang.Math;
import java.util.Scanner;
import java.io.PrintWriter;

public class Main {
  static final double eps = 0.000001;
  
  public static void main( String[] args ) {
	Scanner sc = new Scanner( System.in );
	PrintWriter pf = new PrintWriter( System.out );
	int cases = sc.nextInt(), caseno = 0;
	while( cases>0 ) {
      int a = sc.nextInt();
      String ss = sc.next();
      int b = sc.nextInt();
   
      double r = Math.sqrt(a*a+b*b) / 2.0, theta, s, x;
      theta = 2 * Math.acos( (2*r*r-b*b)/(2*r*r) );
      s = r*theta;
      x = 400/(2.0*a+s);
      double l, w;
      pf.printf("Case %d: %.9f %.9f\n", ++caseno, a*x, b*x);
	  cases--;
	}
	sc.close();
	pf.close();
  }
}
