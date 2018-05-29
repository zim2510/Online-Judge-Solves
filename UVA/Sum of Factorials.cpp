#include <bits/stdc++.h>

using namespace std;

int fac[10];

void faccalc()
{
    fac[0] = 1;
    for(int i = 1; i<10; i++){
        fac[i] = i * fac[i-1];
    }
}

bool psbl(int n, int sp)
{
    int p = 0;
    for(int i = sp; i>=0; i--){
        if(fac[i]==n) {p = 1; break;}
        else if(fac[i]<n){
            if(psbl(n-fac[i], i-1)) {p = 1; break;}
        }
    }
    return p;
}

int main()
{
    faccalc();
    int n;
    while(scanf("%d", &n)==1 && n>=0){
        if(psbl(n, 9)) printf("YES\n");
        else printf("NO\n");
    }
}
