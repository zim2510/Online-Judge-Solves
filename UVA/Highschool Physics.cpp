#include <bits/stdc++.h>

using namespace std;

int main()
{
    char in[10000];
    while(scanf(" %s", in)==1){
        for(int i = 0; in[i]!='\0'; i++){
            printf("%c", in[i]-'1'+'*');
        }
        printf("\n");
    }
}
