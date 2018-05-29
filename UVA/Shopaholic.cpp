#include <bits/stdc++.h>

using namespace std;

#define fRead(x)  freopen(x,"r",stdin)
#define fWrite(x) freopen (x,"w",stdout)

#define LL long long
#define ULL unsigned long long
#define ff first
#define ss second
#define pb push_back
#define INF 2e16
#define PI acos(-1.0)
#define mk make_pair

#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(a,min(b,min(c,d)))
#define max4(a,b,c,d) max(a,max(b,max(c,d)))
#define SQR(a) ((a)*(a))
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define ABS(x) ((x)<0?-(x):(x))

#define scanI(a) scanf("%d",&a)
#define scanI2(a,b) scanI(a) , scanI(b)
#define scanI3(a,b,c) scanI(a), scanI(b), scanI(c)
#define scanI4(a,b,c,d) scanI(a), scanI(b), scanI(c), scanI(d)

#define scanL(a) scanf("%I64d",&a)
#define scanL2(a,b) scanL(a) , scanL(b)
#define scanL3(a,b,c) scanL(a), scanL(b), scanL(c)
#define scanL4(a,b,c,d) scanL(a), scanL(b), scanL(c), scanL(d)

#define SORT(v) sort(v.begin(),v.end())
#define REV(v) reverse(v.begin(),v.end())

#define FastRead ios_base::sync_with_stdio(0);cin.tie(nullptr);

bool csort(long long int a, long long int b);
int pw[100001];
int main()
{
    long long int p, co, ct;
    scanf("%lld %lld %lld", &p, &co, &ct);

    for(int i = 0; i<p; i++){
        scanL(pw[i]);
    }

    sort(pw, pw+p, csort);

    int bgn = min(co, ct);

    double mo = 0, mt = 0;

    for(int i = 0; i<bgn; i++){
        mo += (double) pw[i]/bgn;
        pw[i] = -1;
        if(i>=p) break;
    }


    bgn = max(co, ct);

    for(int i = 0, j = 0; i<bgn;){
        if(pw[j]!=-1){
            mt += (double) pw[j]/bgn;
            i++;
        }
        j++;
        if(j>=p) break;
    }
    printf("%0.9lf\n", mt+mo);
    return 0;
}

bool csort(long long int a, long long int b)
{
    return a>b;
}
