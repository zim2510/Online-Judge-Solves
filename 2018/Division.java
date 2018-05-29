import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main
{
    public static void main(String args[]) throws IOException {
        int l;
        int [] ar = new int[5];
        BufferedReader cin = new BufferedReader(new InputStreamReader(System.in));
        while(true){
            String line, temp ;
            line = cin.readLine();
            if(line.length()==0) break;
            l = 0; temp = "";
            
            for(int i = 0 ; i < line.length() ; ++i)
            {
               if(line.charAt(i) == ' ')
               {
                   ar[l] = Integer.parseInt(temp);
                   temp = "";
                   l++;
               }
               else temp += line.charAt(i);
            } ar[l] = Integer.parseInt(temp);
            
            for(int i = 0 ; i <= l ; ++i){
                System.out.println(ar[i]);
            }
            
            int t, a, b;
            t = ar[0];
            a = ar[1];;
            b = ar[2];;
            
            BigInteger x, y;
            String res;
            x = BigInteger.valueOf(t).pow(a);
            y = BigInteger.valueOf(t).pow(b);
            x = x.add(BigInteger.valueOf(-1));
            y = y.add(BigInteger.valueOf(-1));
            BigInteger m = x.mod(y);
            System.out.print("(" + t + "^"+ a + "-1)"+ "/" + "(" + t + "^" + b + "-1) ");
            if(m.equals(BigInteger.valueOf(0))){
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

