#include <bits/stdc++.h>

using namespace std;

int prime[1000001], primes[1000000],fac[1000000];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<=1000000; i += 2) prime[i] = 1;
    for(int i =3; i*i<=1000000; i+=2){
        if(!prime[i]){
            for(int x = i * i; x<=1000000; x += 2*i){
                prime[x] = 1;
            }
        }
    }
    int n = 0;
    for(int i = 2; i<=1000; i++){
        if(!prime[i]) primes[n++] = i;
    }
}

void calc()
{
    for(int i = 2; i<=1000000; i++){
        int c = 0;
        int s = 0;
        int n = i;
        while(n!=1 && primes[s]*prime[s]<=n && s<168){
            if(!prime[n]) {c += 1; break;}
            if(n%primes[s]) s++;
            else{
                n = n/primes[s];
                s = 0;
                c++;
            }
        }
        fac[i] = fac[i-1] + c;
    }
}

int main()
{
    siv();
    calc();
    int n;
    while(scanf("%d", &n) != EOF){
        int c = 0;
        //for(int i = 2; i<=n; i++) c += fac[i];
        printf("%d\n", fac[n]);
    }
}
