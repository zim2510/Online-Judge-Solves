import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String args[]){
        Scanner cin = new Scanner(System.in);
        int b;
        String p, m;
        while(cin.hasNext()){
            b = cin.nextInt();
            if(b==0) break;
            p = cin.next();
            m = cin.next();
            BigInteger x = new BigInteger(p, b);
            BigInteger y = new BigInteger(m, b);
            BigInteger r = x.mod(y);
            System.out.println(r.toString(b));
        }
    }
}
