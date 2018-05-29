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
#define sz(a)             int((a).size()) 
#define all(c)            (c).begin(),(c).end() 
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               1000000000

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

int mark[10], n, cnt;

void btrack(int ci, int llft, int lrgt)
{
    if((llft/(lrgt+1))>n) return;
    if(ci>2 && (((llft+1)/lrgt)+1)<n) return;
    if(ci==5){
        if(lrgt*n==llft) {
            cnt++;
            if(lrgt<10000) printf("%5d / 0%d = %d\n", llft, lrgt, n);
            else printf("%5d / %5d = %d\n", llft, lrgt, n);
        }
    }
    for(int i = 0; i<10; i++){
        if(!mark[i]){
            mark[i] = 1;
            for(int j = 0; j<10; j++){
                if(!mark[j]){
                    mark[j] = 1;
                    btrack(ci+1, llft*10+i, lrgt*10+j);
                    mark[j] = 0;
                }
            }
            mark[i] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc = 0;
    while(scanf("%d", &n) && n){
        if(tc) printf("\n");
        tc++;
        cnt = 0;
        btrack(0, 0, 0);
        if(!cnt) printf("There are no solutions for %d.\n", n);
    }

}