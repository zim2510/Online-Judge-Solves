#include <bits/stdc++.h>

using namespace std;
void backtrack(int n);
int isprime(int n);
int out[20], mark[20], m;
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int i = 1;
    while(scanf("%d", &m)==1){
        printf("Case %d:\n", i++);
        memset(out, 0, sizeof(out));
        memset(mark, 0, sizeof(mark));
        out[0] = 1;
        mark[1] = 1;
        backtrack(1);
        printf("\n");
    }
}

void backtrack(int n)
{
    for(int i = 2; i<=m; i++){
        if(n==m-1 && mark[i]==0){
            if(isprime(1+i) && isprime(out[n-1]+i)){
                mark[i] = 1;
                out[n] = i;
                for(int i = 0; i<m-1; i++){
                    printf("%d ", out[i]);
                }
                printf("%d\n", out[m-1]);
                mark[i] = 0;
            }
        }
        else if(mark[i]==0){
            if(isprime(out[n-1]+i)){
                mark[i] = 1;
                out[n] = i;
                backtrack(n+1);
                mark[i] = 0;
            }
        }
    }
}

int isprime(int n)
{
    if(n==1) return 0;
    if(n!=2 && n%2==0) return 0;
    if(n!=3 && n%3==0) return 0;
    if(n!=5 && n%5==0) return 0;
    return 1;
}
