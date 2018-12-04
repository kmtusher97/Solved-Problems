import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    static BigInteger[] ff = new BigInteger[102];
    
    public static void main(String[] args) {
       Scanner sc = new Scanner( System.in );
       ff[0] = new BigInteger("1");
       for(int i=1; i<=101; i++) {
           ff[i] = ff[i-1].multiply(BigInteger.valueOf(i));
       }
       int cases = sc.nextInt();
       while( cases-->0 ) {
           int n = sc.nextInt();
           System.out.println(ff[n]);
       }
    }
    
}
