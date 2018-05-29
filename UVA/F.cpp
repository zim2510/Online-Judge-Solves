#include <bits/stdc++.h>

using namespace std;

int prime[1001];
int primes[170];

void siv()
{
    prime[0] = 1;
    for(int i = 4; i<=1000; i += 2) prime[i] = 1;
    for(int i = 3; i<1000; i += 2){
        if(prime[i]==0){
            for(int j = i*2; j<1000; j+=i){
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    siv();
    int y = 0;
    for(int i = 0; i<=1000; i++){
        if(prime[i]==0) primes[y++] = i;
    }

    int n, c;
    while(scanf("%d %d", &n, &c)==2){
        printf("%d %d:", n, c);
        int i, cut = 0;
        for(i = 0; primes[i]<=n && i<169; i++);
        if(i%2){
            if(i>=c*2-1) cut = (i - c*2 + 1)/2;
            for(int x = cut; x<i-cut && x<169; x++){
                printf(" %d", primes[x]);
            }
        }
        else{
            if(i>=c*2) cut = (i - c*2)/2;
            for(int x = cut; x<i-cut && x<169; x++){
                printf(" %d", primes[x]);
            }
        }
        printf("\n\n");
    }
}
