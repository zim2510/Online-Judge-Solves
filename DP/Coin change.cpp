#include <bits/stdc++.h>

using namespace std;

int cents[] = {50, 25, 10, 5};
int opt[4][7500];

int dp(int t, int typ)
{
    if(t==0 || (t>0 && typ==4)) return 1;
    if(t<0) return 0;
    if(opt[typ][t]!=0) return opt[typ][t];
    opt[typ][t] = dp(t-cents[typ], typ) + dp(t, typ+1);
    return opt[typ][t];
}

int add(char * a, char * b)
{
    int len1 = strlen(a);
    int len2 = strlen(b);

}

int main()
{
    int n;
    //memset(opt, -1, sizeof(opt));
    while(scanf("%d", &n) == 1){
        printf("%d\n", dp(n, 0));
    }
}
