
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

int main()
{
    int tc;
    scanI(tc);

    FOR(i, 1, tc){
        int npoint, nseg;
        scanI2(npoint, nseg);
        int points[npoint];

        REP(i, npoint){
            scanI(points[i]);
        }
        printf("Case %d:\n", i);
        sort(points, points+npoint);
        REP(i, nseg){
            int bgin, fnsh;
            scanI2(bgin, fnsh);
            int lo1 = 0, hi1 = npoint - 1, mid1 = 0;
            if(bgin<=points[npoint-1] && fnsh>=points[0]) while(lo1<=hi1){
                mid1 = (hi1 + lo1) / 2;
                if(points[mid1] == bgin || (points[mid1]>bgin && points[mid1-1]<bgin)){
                    break;
                }
                else if(points[mid1]<bgin){
                    lo1 = mid1 + 1;
                }
                else hi1 = mid1 - 1;
            }

            int lo2 = 0, hi2 = npoint - 1, mid2 = 0;
            if(bgin<=points[npoint-1] && fnsh>=points[0]) while(lo2<=hi2){
                mid2 = (hi2 + lo2) / 2;

                if( points[mid2] == fnsh || (points[mid2]<fnsh && points[mid2+1]>fnsh)){
                    break;
                }
                else if(points[mid2]>fnsh){
                    hi2 = mid2 - 1;
                }
                else lo2 = mid2 + 1;
            }
            if(!mid1 && !mid2) printf("0\n");
            else printf("%d\n", mid2 - mid1 + 1);

        }

    }
}
