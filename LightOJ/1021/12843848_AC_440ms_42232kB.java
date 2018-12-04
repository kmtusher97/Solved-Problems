import java.util.Scanner;

public class Main
{
  public static void main( String[] args )
  {
	Scanner sc = new Scanner( System.in );
	int cases, caseno = 0;
	cases = sc.nextInt();
	while( cases>0 ) 
	{
	  int n, b, k;
	  b = sc.nextInt();
	  k = sc.nextInt();
	  String nm = sc.next();
	  n = nm.length();
	  int[] d = new int[n];
	  for(int i=0; i<n; i++)
	  {
		if( nm.charAt(i)>='0' && nm.charAt(i)<='9' ) d[i] = nm.charAt(i)-'0'; 
		else d[i] = nm.charAt(i)-55;
	  }
	  
	  long[][] ff = new long[(1<<n)+2][k+1];
	  ff[0][0] = 1;
	  for(int mask=0; mask<(1<<n); mask++)
	  {
		for(int mod=0; mod<k; mod++) 
		{
		  if( ff[mask][mod]==0 ) continue;
		  for(int i=0; i<n; i++) 
		  {
			if( (mask & (1<<i))!=0 ) continue;
			ff[(mask | (1<<i))][(mod*b + d[i])%k] += ff[mask][mod];
		  }
		}
	  }
	  
	  System.out.printf("Case %d: %d\n", ++caseno, ff[(1<<n)-1][0]);
	  cases--;
	}
  }
}