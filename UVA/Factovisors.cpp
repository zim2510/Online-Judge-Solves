#include <bits/stdc++.h>
#define MAX 50000
using namespace std;

int prime[MAX];
int nprime[5135];

vector<int> m;

void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<MAX; i += 2){
        prime[i] = 1;
    }
    for(int i = 3; i*i<MAX; i += 2){
        if(!prime[i]){
            for(int x = i*i; x<MAX; x += 2*i){
                prime[x] = 1;
            }
        }
    }
    int x = 0;
    for(int i = 2; i<MAX; i++){
         if(prime[i]==0) nprime[x++] = i;
    }
}

void factorize(int n){
    m.clear();
    if(n<2){
        if(n==1) m.push_back(1);
        return;
    }
    int x = 0;
    while(n!=1){
        if(x == 5135 || nprime[x]*nprime[x]>n){
            //printf("%lld\n", n);
            m.push_back(n);
            n = 1;
        }
        else if(n<MAX && !prime[n]){
            //printf("%lld\n", n);
            m.push_back(n);
            n = 1;
        }
        else if(n%nprime[x] == 0){
            m.push_back(nprime[x]);
            //printf("%d\n", nprime[x]);
            n = n/nprime[x];
            x = 0;
        }
        else x++;
    }
}

int check(int n)
{
    int pos = 0;
    int j = 0;
    int s = m.size();
    for(int i = m[j]; i<=n; i += m[j]){
        int x = i;
        while(x%m[j]==0){
            x = x/m[j];
            j++;
            if(j == s){
                pos = 1;
                break;
            }
        }
        if(m[j]!=m[j-1]) i = 0;
        if(pos) break;
    }
    return pos;
}


int main()
{
    //freopen("out.txt", "w", stdout);
    siv();
    int n, b;
    while(scanf("%d %d", &n, &b) == 2){
        if(n>=b){
            printf("%d divides %d!\n", b, n);
            continue;
        }
        else if(n==0){
            if(b==1) printf("%d divides %d!\n", b, n);
            else printf("%d does not divide %d!\n", b, n);
            continue;
        }
        factorize(b);
        int x = check(n);
        if(x) printf("%d divides %d!\n", b, n);
        else printf("%d does not divide %d!\n", b, n);
    }
    return 0;
}
