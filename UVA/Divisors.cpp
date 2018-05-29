#include <bits/stdc++.h>
#define ll long LONG_MAX
#define MAX 31650
using namespace std;

int prime[MAX];
int nprime[3405];
int cnt[3405];

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<MAX; i+=2) prime[i] = 1;
    for(int i = 3; i*i<MAX; i+=2){
        if(prime[i]==0){
            for(int x = i*i; x<MAX; x+=2*i){
                prime[x] = 1;
            }
        }
    }
    int x = 0;
    for(int i = 0; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

void calc(int lo, int hi)
{
    int mx = 0, mxc = 0;

    for(int i = lo; i<=hi; i++){
        int x = 0, s = 0;
        int n = i;

        cnt[0] = 0;

        while(n!=1){
            if(x>3403){
                s++;
                cnt[s] = 1;
                s++;
                n = 1;
            }
            else if(n%nprime[x]==0){
                cnt[s]++;
                n /= nprime[x];
                if(n==1) s++;
            }
            else{
                x++;
                s++;
                cnt[s] = 0;
            }
        }


        int total = 1;
        for(int i = 0; i<s; i++){
            total *= cnt[i] + 1;
        }

        if(total>mx){
            mx = total;
            mxc = i;
        }
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n", lo, hi, mxc, mx);
}



int main()
{
    siv();
    int tc;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        int lo, hi;
        scanf("%d %d", &lo, &hi);
        calc(lo, hi);
    }
    return 0;

}
