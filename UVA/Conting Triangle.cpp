#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

long long int seg[2000];

ll bin(ll lo, ll hi, ll mx);
int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int n, cnt = 0;
        scanf("%d", &n);
        for(int i = 0; i<n; i++) scanf("%lld", &seg[i]);
        sort(seg, seg+n);
        for(int a = 0; a<n-2; a++){
            for(int b = a+1; b<n-1; b++){
                //printf("Sending: %d %d\n", seg[a], seg[b]);
                int mx = seg[a] + seg[b];
                cnt += bin(b+1, n, mx);
            }
        }
        printf("Case %d: %d\n", i, cnt);
    }
}

ll bin(ll lo, ll hi, ll mx)
{
    int sp = lo;
    /*printf("Hi: %d Lo: %d\n", hi, lo);
    if(hi==lo){
        if(seg[hi]<mx) printf("Count: %d\n", 1);
    }*/

    while(hi!=lo){
        int mid = (hi+lo)/2;
        //printf("H: %d L: %d M: %d\n", hi, lo, mid);
        //printf("Max: %d Current: %d\n", mx, seg[mid]);
        if(seg[mid]<mx) lo = mid + 1;
        else hi = mid;
    }
    int cnt = hi - sp;
    if(cnt>0) return cnt;
    else return 0;
    //printf("Count: %d\n\n", hi - sp);
    //printf("%d %d\n", hi, seg[sp-1]);
}
