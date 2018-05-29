import java.io.NotActiveException;
import java.math.BigInteger;
import java.util.Scanner;

import javax.swing.event.AncestorEvent;
import javax.swing.text.html.HTMLDocument.HTMLReader.IsindexAction;

class Product
{
	public static void main(String args[]) {
		int t, a, b;
		BigInteger x, y;
		String res;
		Scanner cin = new Scanner(System.in);

		while(cin.hasNext()){
			t = cin.nextInt();
			a = cin.nextInt();
			b = cin.nextInt();
			System.out.print("(" + t + "^"+ a + "-1)"+ "/" + "(" + t + "^" + b + "-1) ");
			if(t==1){
				System.out.println("is not an integer with less than 100 digits.");
				continue;
			}

			if(a==b){
				System.out.println("1");
			}

			x = BigInteger.valueOf(t).pow(a);
			y = BigInteger.valueOf(t).pow(b);
			x = x.add(BigInteger.valueOf(-1));
			y = y.add(BigInteger.valueOf(-1));
			BigInteger m = x.mod(y);
			if(m.equals(0)) {
				x = x.divide(y);
				res = x.toString();
				if(res.length()<100) System.out.println(x);
				else System.out.println("is not an integer with less than 100 digits.");
				continue;
			}
			System.out.println("is not an integer with less than 100 digits.");
		}
	}
}
