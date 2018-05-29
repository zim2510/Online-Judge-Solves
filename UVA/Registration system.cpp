#include <bits/stdc++.h>
#define MOD 1000007
typedef long long ll;
using namespace std;


int main()
{
    int tc;
    map<string, int> cnt;
    scanf("%d", &tc);
    for(int i = 0; i<tc; i++){
        char in[33];
        scanf(" %s", in);
        if(cnt[in]==0) printf("OK\n");
        else printf("%s%d\n", in, cnt[in]);
        cnt[in]++;
    }
    return 0;
}
