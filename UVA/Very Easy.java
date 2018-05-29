import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			int n;
			BigInteger a;
			n = cin.nextInt();
			a = cin.nextBigInteger();
			BigInteger result = new BigInteger(0);
			for(int i = 1; i<=n; i++){
				result = result.add(a.pow(i).multiply(valueof(i)));
			}
		}
	}
}