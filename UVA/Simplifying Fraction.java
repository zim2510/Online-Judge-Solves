import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static BigInteger gcd(BigInteger x, BigInteger y){
		if(y.equals(BigInteger.valueOf(0))){
			return x; 
		}
		else return gcd(y, x.mod(y));
	}

	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int tc;
		tc = cin.nextInt();
		for(int i = 1; i<=tc; i++){
			BigInteger p = cin.nextBigInteger();;
			String ignore;
                        ignore = cin.next();
			BigInteger q = cin.nextBigInteger();
			BigInteger g = gcd(p, q);
			System.out.println(p.divide(g) + " / " + q.divide(g));
		}
	}
}