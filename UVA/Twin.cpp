#include <bits/stdc++.h>

using namespace std;

int prime[20000000];
long long primes[1270607];

struct twin
{
    long long one, two;
};

twin nums[100000];

void siv(long long int n)
{
    for(long long int i = 4; i<n; i+=2){
        prime[i] = 1;
    }
    long long c = 0;
    for(long long int i = 3; i*i<n; i++){
        if(prime[i]==0){
            for(long long int x = i*i; x<n; x+=i){
                prime[x] = 1;
            }
        }
    }

    c = 0;
    for(long long int i = 2; i<20000000; i++){
        if(prime[i]==0) primes[c++] = i;
    }
}

void precalc()
{
    long long int c = 0;
    for(long long int n = 1; c<100000; n++){
        if((primes[n] - primes[n-1]) == 2){
            nums[c].one = primes[n-1];
            nums[c].two = primes[n];
            c++;
        }
    }
}

int main()
{
    siv(20000000);
    precalc();
    long long int n;
    while(scanf("%lld", &n) == 1){
        printf("(%lld, %lld)\n", nums[n-1].one, nums[n-1].two);
    }

    return 0;
}
