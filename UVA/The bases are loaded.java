import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		BigInteger result;
                while(cin.hasNext()){
                    int fbase, tbase;
                    String num;
                    fbase = cin.nextInt();
                    tbase = cin.nextInt();
                    num = cin.next();
                    
                    try{
                        result = new BigInteger(num, fbase);
                    }catch(NumberFormatException x){
                        System.out.println(num + " is an illegal base " + fbase + " number");
                        continue;
                    }
                    String res = result.toString(tbase).toUpperCase();
                    System.out.println(num + " base " + fbase + " = " + res + " base " + tbase);
		}
	}
}