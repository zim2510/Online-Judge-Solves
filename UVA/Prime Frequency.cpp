#include <bits/stdc++.h>

using namespace std;
bool prime[2001];
void siv()
{
    prime[0] = prime[1] = 1;
    for(int i = 4; i<2001; i+=2) prime[i] = 1;
    for(int i = 3; i*i<2001; i+=2){
        if(!prime[i]){
            for(int x = i*i; x<2001; x+=2*i) prime[x] = 1;
        }
    }
}


int main()
{
    siv();
    int cnt[256], tc;

    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        memset(cnt, 0, sizeof(cnt));
        char str[2001];
        scanf(" %s", str);
        for(int i = 0; str[i]!='\0'; i++){
            cnt[str[i]]++;
        }
        printf("Case %d: ", i);
        int p = 0;
        for(int i = 0; i<256; i++){
            if(!prime[cnt[i]]) p = 1;
            if(!prime[cnt[i]]) printf("%c", i);
        }
        if(!p) printf("empty");
        printf("\n");
    }
}
