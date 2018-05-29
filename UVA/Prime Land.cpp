#include <bits/stdc++.h>
#define MAX 32768
#define pb push_back

using namespace std;

bool prime[MAX];
int nprime[3512];

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
    for(int i = 0; i<MAX; i++){
        if(!prime[i]) nprime[x++] = i;
    }
}

int power(int n, int p)
{
    int x = 1;
    for(int i = 1; i<=p; i++){
        x *= n;
    }
    return x;
}

void fac(int n)
{
    int p[1000], po[1000];

    int x, ps = 0;

    x = upper_bound(nprime, nprime+3512, n) - nprime;

    for(int i = x; i>=0 && n!=1; i--){
        int y = 0;
        while(n%nprime[i]==0){
            y++;
            n = n/nprime[i];
        }
        if(y>0){
            p[ps] = nprime[i];
            po[ps++] = y;
        }
    }
    printf("%d %d", p[0], po[0]);
    for(int i = 1; i<ps; i++){
        printf(" %d %d", p[i], po[i]);
    }
    printf("\n");
}

int main()
{
    siv();
    string s;
    while(EOF){
        getline(cin, s);
        stringstream in(s);
        vector<int> v;
        int tmp;
        while(in>>tmp){
            v.pb(tmp);
        }
        int sz = v.size();
        if(sz==1) break;
        int n = 1;
        for(int i = 0; i<sz; i+=2){
            n *= power(v[i], v[i+1]);
        }
        fac(n-1);
    }
}
