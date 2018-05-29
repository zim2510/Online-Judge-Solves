#include <bits/stdc++.h>
#define MAX 1000000

using namespace std;
int prime[MAX], nprime[78500];
void siv()
{
    prime[0] = prime[1] = 1;

    for(int i = 4; i<MAX; i+=2){
        prime[i] = 1;
    }

    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<MAX; x+=2*i){
                prime[x] = 1;
            }
        }
    }
    int x = 0;
    for(int i = 2; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

int main()
{
    siv();
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        long long lo, hi, cnt = 0;
        scanf("%lld %lld", &lo, &hi);
        long long lmt = sqrt(hi);


        for(int i = 0; i<78498 && nprime[i]<=lmt; i++){
            for(long long int n = (long long) nprime[i]*nprime[i]; n<=hi; n = (long long) n * nprime[i]){
                if(n>=lo && n<=hi) cnt++;
            }
        }
        printf("%lld\n", cnt);
    }
    return 0;
}

