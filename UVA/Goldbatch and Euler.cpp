#include <bits/stdc++.h>
#define M 100000000
using namespace std;

bool prime[100000000];
int nprime[5761455];

void siv()
{
    int n = 0, x, i;
    nprime[n++] = 2;
    int lim = 10000;
    prime[0] = prime[1] = 1;
    for(i = 3; i<M; i+=2){
        if(!prime[i]){
            nprime[n++] = i;
            if(i>lim) continue;
            for(x = i*i; x<M; x+=2*i) prime[x] = 1;
        }
    }
}

int main()
{

    //freopen("out.txt", "w", stdout);
    siv();
    int n, i, f, x;
    while(scanf("%d", &n)==1){
        if(n%2 && n>2){
            if(!prime[n-2]) printf("%d is the sum of %d and %d.\n", n, 2, n-2);
            else printf("%d is not the sum of two primes!\n", n);
        }

        else{
            f = 0;
            x = upper_bound(nprime, nprime+5761455, n/2) - nprime;
            for(i = x; nprime[i]<n; i++){
                if(!prime[n-nprime[i]]){
                    printf("%d is the sum of %d and %d.\n", n, n - nprime[i], nprime[i]);
                    f = 1;
                    break;
                }
            }
            if(!f) printf("%d is not the sum of two primes!\n", n);
        }
    }
    return 0;
}
