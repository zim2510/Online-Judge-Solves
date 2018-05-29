#include <bits/stdc++.h>
#define ll long long
#define MAX 50001
#define pb push_back
using namespace std;

int prime[MAX], nprime[5200];
vector <int> factors;
void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<MAX; x+=2*i) prime[x] = 1;
        }
    }
    int x = 0;
    for(int i = 2; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

void phi(int n)
{
    factors.clear();
    int x = n;
    if(x==1) {printf("%d\n", 1); return;}
    int lmt = sqrt(n);
    for(int i = 0; nprime[i]<=lmt; i++){
        if(n%nprime[i]==0){
            factors.pb(nprime[i]);
            while(n%nprime[i] == 0) n /= nprime[i];
        }
    }
    if(n!=1) factors.pb(n);
    int len = factors.size();


    for(int i = 0; i<len; i++){
        // x = (x / factors[i])* (factors[i]-1);
        x-=x/factors[i];
    }
    printf("%d\n", x);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    siv();
    int n;
    while(scanf("%d", &n) == 1 && n){
        phi(n);
    }
    return 0;
}


