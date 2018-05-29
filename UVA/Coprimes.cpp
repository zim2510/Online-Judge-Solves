#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int part[30];
int n, p;
void btrack(int pos, int m, int left, int g)
{
    //printf("%d %d %d %d\n", pos, m, left, g);
    if(left==0 && pos==p){
        printf("%d", part[0]);
        for(int i = 1; i<p; i++) printf(" %d", part[i]);
        printf("\n");
        return;
    }

    if(pos==p || left==0) return;

    for(int i = m; i<=left; i++){
        if(__gcd(g, i)==1){
            part[pos] = i;
            btrack(pos+1, i, left-i, g*i);
            part[pos] = 0;
        }
    }
}


int main(int argc, char const *argv[])
{
    //Read();
    //Write();
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        scanf("%d %d", &n, &p);
        printf("Case %d:\n", i);
        btrack(0, 1, n, 1);
    }

    return 0;
}
