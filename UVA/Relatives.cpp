#include <bits/stdc++.h>
#define ll long long
#define MAX 31623
#define pb push_back
using namespace std;

int prime[31623], nprime[3410];
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
    for(int i = 2; i<31623; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

void phi(int n)
{
    factors.clear();
    int x = n;
    for(int i = 0; i<3401 && nprime[i]<=n && n>1; i++){
        if(n<31623 && !prime[n]){
            factors.pb(n);
            n = 1;
        }
        else if(n%nprime[i]==0){
            factors.pb(nprime[i]);
            while(n%nprime[i] == 0) n /= nprime[i];
        }
        else if(i==3400){
            factors.pb(n);
            n = 1;
        }
    }

    if(x==1) factors.pb(1);
    int len = factors.size();


    for(int i = 0; i<len; i++){
        x = (x / factors[i])* (factors[i]-1);
    }
    printf("%d\n", x);
}

int main()
{
    siv();
    int n;
    while(scanf("%d", &n) == 1 && n){
        phi(n);
    }
    return 0;
}

