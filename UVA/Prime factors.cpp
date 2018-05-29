#include <bits/stdc++.h>

int prime[1000000], primes[100000];

void siv(int n)
{
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 4; i<n; i += 2) prime[i] = 1;

    for(int i = 3; i*i<n; i++){
        if(!prime[i]){
            for(int x = i*i; x<n; x += 2*i) prime[x] = 1;
        }
    }
    int c = 0;
    for(int i = 2; i<n; i++){
        if(prime[i] == 0) primes[c++] = i;
        //if(prime[i] == 0) printf("%d\n", i);
    }
}

void factorize(long long n)
{

    printf("%lld = ", n);
    int start = 0;

    if(n<0){
        printf("-1");
        start = 1;
        n = n * -1;
    }

    long long lmt = sqrt(n);

    while(n!=1){
        for(int i = 0; primes[i] <= lmt; i++){
            if(n%primes[i] == 0){
                if(start){
                    printf(" x %d", primes[i]);
                }
                else{
                    printf("%d", primes[i]);
                    start++;
                }
                n = n/primes[i];
                lmt = sqrt(n);
                i = -1;
            }
        }
        if(n>1 && start) printf(" x %lld", n);
        else if(n>1 && !start) printf("%lld", n);
        n = 1;
    }
    printf("\n");
}

int main()
{
    siv(1000000);
    while(1){
        int n;
        scanf("%lld", &n);
        if(n == 0) break;
        factorize(n);
    }
}
