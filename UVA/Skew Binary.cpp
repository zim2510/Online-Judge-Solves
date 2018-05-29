#include <bits/stdc++.h>
#define MAX 100001
#define READ() freopen("in.txt", "r", stdin)
#define WRITE() freopen("out.txt", "w", stdout)
using namespace std;

int main()
{
    READ();
    WRITE();
    char in[50];
    while(scanf(" %s", in)==1){
        if(!strcmp(in, "0")) break;
        int len = strlen(in);
        int num = 0, m = 2;
        for(int i = len - 1; i>=0; i--){
            num += (in[i] - '0') * (m-1);
            m *= 2;
        }
        printf("%d\n", num);
    }
}
