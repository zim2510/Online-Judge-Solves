#include <bits/stdc++.h>
#define MOD 10000007
typedef long long ll;

using namespace std;

long long power[100000];

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
    power[0] = 1;
    for(int i = 1; i<100000; i++){
        power[i] = (power[i-1]*2510)%MOD;
    }
}

int main()
{
    basecalc();
    char input[100001];
    while(scanf(" %s", input)==1){
        int len = strlen(input);
        long long normal[100000], opposite[100000];
        int last = 0;
        for(int i = 0; i<len; i++){
            normal[i] = hasher(last, input[i]);
            last = normal[i];
        }
        last = 0;
        for(int i = len-1; i>=0; i--){
            opposite[i] = hasher(last, input[i]);
            last = opposite[i];
        }

        printf("%s", input);

        if(normal[len-1]==opposite[0]){
            printf("\n");
            continue;
        }
        int ptr;
        for(ptr = 0; ptr<len-1; ptr++){
            long long hashed = gethash(normal[ptr], normal[len-1], len-1-ptr);
            if(hashed==opposite[ptr+1]) break;
        }
        for(; ptr>=0; ptr--) printf("%c", input[ptr]);
        printf("\n");

    }
    return 0;
}
