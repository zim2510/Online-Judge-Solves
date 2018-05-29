#include <bits/stdc++.h>
#define MAX 10001

int prime[10001], nprime[1275];

void siv()
{
    for(int i = 4; i<MAX; i+=2){
        prime[i] = 1;
    }
    for(int i = 3; i*i<MAX; i+=2){
        if(!prime[i])for(int x = i*i; x<MAX; x+=2*i){
            prime[x] = 1;
        }
    }
    int x = 0;
    for(int i = 2; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
    //printf("%d %d\n", nprime[x-1], x);
}

int main()
{
    siv();
    int x;
    while(scanf("%d", &x) && x){
        int cnt = 0;
        for(int i = 2; i<=x; i++){
            int sum = 0;
            //printf("%d\n", i);
            if(!prime[i]) for(int j = i; j<=x; j++){
                if(!prime[j]) sum += j;
                if(sum==x) {cnt++; break;}
                else if(sum>x) break;
                //printf("S: %d %d\n", sum, i);
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
