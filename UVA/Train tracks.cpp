#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> cnt;

    int tc;
    scanf("%d", &tc);
    getchar();
    for(int i = 0; i<tc; i++){
        cnt['M'] = cnt['F'] = 0;
        while(1){
            char c = getchar();
            if(c == '\n') break;
            else cnt[c]++;

        }
        if(cnt['M'] == cnt['F'] && cnt['M']!=1) printf("LOOP\n");
        else printf("NO LOOP\n");
    }
}
