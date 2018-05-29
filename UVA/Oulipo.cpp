#include <bits/stdc++.h>
#define MOD 10000007
typedef long long ll;

using namespace std;

long long power[1000000];
long long hashed[1000000];
char w[10000], t[1000001];

long long hasher(long long last, int ch)
{
    long long x = (last*2510+ch)%MOD;
    return x;
}

long long gethash(long long sp, long long ep, long long pd)
{

    //printf("%lld %lld\n", ep, (sp*power[pd])%MOD);
    long long x = (ep - (sp * power[pd]))%MOD;
    if(x<0) x += MOD;
    return x;
}


void basecalc()
{
    //printf("HERE\n");
    power[0] = 1;
    for(int i = 1; i<1000000; i++){
        power[i] = (power[i-1]*2510)%MOD;
    }
}

int main()
{
    basecalc();
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        scanf(" %s %s", w, t);

        hashed[0] = 0;
        int len1 = strlen(w);
        int len2 = strlen(t);
        int cnt = 0;
        long long chash = 0;

        for(int i = 0; i<len1; i++){
            chash = hasher(chash, w[i]);
        }


        for(int i = 1; i<=len2; i++){
            hashed[i] = hasher(hashed[i-1], t[i-1]);

        }

        for(int i = len1; i<=len2; i++){
            long long x = gethash(hashed[i-len1], hashed[i], len1);
            if(x==chash) cnt++;
        }

        printf("%d\n", cnt);
    }
}
