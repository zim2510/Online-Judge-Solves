import java.math.BigInteger;
import java.util.Scanner;

class Main
{
	public static void main(String args[]){
		Scanner scanf = new Scanner(System.in);
		BigInteger a, b;
		while(scanf.hasNextBigInteger()){
			a = scanf.nextBigInteger();
			b = scanf.nextBigInteger();
			System.out.println(a.multiply(b));
		}
	}
}