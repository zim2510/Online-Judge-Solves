#include <bits/stdc++.h>
#define min3(a, b, c) min(a, min(b, c))

using namespace std;

int opt[1000001], n;
int path[1000001];

int dp(int x)
{
    //printf("%d\n", x);
    if(x>n) return 10000000;
    if(x==n) return 0;
    if(opt[x]!=-1) return opt[x];
    else opt[x] = 1 + min3(dp(x+1),  dp(x*2), dp(x*3));

    if(opt[x]-1==dp(x+1)) path[x] = x+1;
    else if(opt[x]-1==dp(x*2)) path[x] = x*2;
    else if(opt[x]-1==dp(x*3)) path[x] = x*3;

    return opt[x];

}

int main()
{
    while(1){memset(opt, -1, sizeof(opt));
    scanf("%d", &n);
    int r = dp(1);
    path[0] = 1;
    printf("%d\n", r);
    printf("1");
    int i = 1;
    while(path[i]>0){
        printf(" %d", path[i]);
        i = path[i];
    }
    printf("\n");}
}
