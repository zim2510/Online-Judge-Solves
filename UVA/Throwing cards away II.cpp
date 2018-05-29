#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size())
#define all(c)            (c).begin(),(c).end()
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)      ((c).find(x) != (c).end())
#define cpresent(c,x)     (find(all(c),x) != (c).end())
#define pb                push_back
#define MAX               2000000000
#define ff                first
#define ss                second
#define sf                scanf
#define pf                printf

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    //Read();
    //Write();
    vector <long long> numbers;
    LL num2 = 1;
    for(int two = 1; two<32; two++){
        if(num2>MAX) break;
        LL num3 = 1;
        for(int three = 1; three<32; three++){
            if(num3*num2>MAX) break;
            LL num5 = 1;
            for(int five = 1; five<32; five++){
                if(num2*num3*num5>MAX) break;
                LL num7 = 1;
                for(int seven = 1; seven<32; seven++){
                    if(num2*num3*num5*num7>MAX && num2*num3*num5*num7>0) break;
                    numbers.pb(num2*num3*num5*num7);
                    num7 *= 7;
                }
                num5 *= 5;
            }
            num3 *= 3;
        }
        num2 *= 2;
    }
    sort(numbers.begin(), numbers.end());
    int n;
    while(scanf("%d", &n) && n){
        string bal;
        if(n%100>=11 && n%100<=19) bal = "th";
        else if(n%10==1) bal = "st";
        else if(n%10==2) bal = "nd";
        else if(n%10==3) bal = "rd";
        else bal = "th";
        cout<<"The "<<n<<bal<<" humble number is "<<numbers[n-1]<<".\n";
    }

}
