#include <bits/stdc++.h>

using namespace std;

int cmp[1001], nc, nd;
long long bin(int lo, int hi);
void print(int mx);
int main()
{
    freopen("out.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        int lo = 0, hi = 0;
        scanf("%d %d", &nc, &nd);
        nc++;
        nd++;
        for(int i = 0; i<nc; i++){
            scanf("%d", &cmp[i]);
            hi += cmp[i];
            if(cmp[i]>lo) lo = cmp[i];
        }
        int mx = bin(lo, hi);
        printf("Case %d: %d\n", i, mx);
        print(mx);
    }
}

long long bin(int lo, int hi)
{
    int mid;
    while(hi>=lo){
        mid = (hi+lo)/2;
        if(hi==lo) break;
        int p=0, np=1;
        for(int i = 0; i<nc; i++){
            if(p+cmp[i]>mid){
                np++;
                p = cmp[i];
            }
            else p += cmp[i];
        }
        if(np<=nd) hi = mid;
        else lo = mid + 1;
    }
    return mid;
}

void print(int mx)
{

    for(int i = nd, j = 0; i>0; i--){
        int p = 0;
        for(;(nc-j)>=i;j++){
            if(p + cmp[j] > mx) break;
            p += cmp[j];
        }
        printf("%d\n", p);
    }
}
