#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int p[n], t[n], pe[n];
    int np = 0, nt = 0, npe = 0;
    for(int i = 1; i<=n; i++){
        int x;
        scanf("%d", &x);
        if(x==1) p[np++] = i;
        else if(x==2) t[nt++] = i;
        else if(x==3) pe[npe++] = i;
    }
    int x = min(np, min(nt, npe));
    printf("%d\n", x);
    for(int i = 0; i<x; i++){
        printf("%d %d %d\n", p[i], t[i], pe[i]);
    }
}
