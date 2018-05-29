#include <bits/stdc++.h>

using namespace std;

int cmp[1001], nc, nd;
long long bin(int lo, int hi);

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

        int p = 0, d = 0;
        for(int i = 0; i<=nc; i++){
            if(nd - d == nc - i){
                printf("%d\n", cmp[i]);
                d++;
            }
            else if(p+cmp[i]>mx || i == nc){
                if(i==nc) printf("%d\n", p);
                else{
                    printf("%d\n", p);
                    p = cmp[i];
                    if(nd - d == nc - i){
                        printf("%d\n", cmp[i]);
                        d++;
                    }
                }
            }
            else p += cmp[i];
        }
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
