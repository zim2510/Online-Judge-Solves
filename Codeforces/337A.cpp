#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, p, mn = 100000000;
    scanf("%d %d", &n, &p);
    int pcs[p];
    for(int i = 0; i<p; i++) scanf("%d", &pcs[i]);
    sort(pcs, pcs+p);

    int dif[p - 1];
    for(int i = 1; i<p; i++) dif[i-1] = pcs[i] - pcs[i-1];

    for(int i = 0; i<=(p-1)-(n-1); i++){
        int d = 0;
        for(int j = 0; j<n-1; j++){
            d += dif[i+j];
        }
        if(d<mn) mn = d;
    }
    printf("%d\n", mn);
}
