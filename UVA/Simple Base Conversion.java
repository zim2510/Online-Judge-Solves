import java.util.Scanner;
import java.math.BigInteger;

class Main
{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
                    String input = cin.next();
                    if(input.charAt(0)=='-') break;
                    if(input.length()>1 && input.charAt(1)=='x'){
                        BigInteger res = new BigInteger(input.substring(2), 16);
                        System.out.println(res.toString(10));
                    }
                    else{
                        BigInteger res = new BigInteger(input, 10);
                        System.out.println("0x" + res.toString(16).toUpperCase());
                    }
		}
	}
}