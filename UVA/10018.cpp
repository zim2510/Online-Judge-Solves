#include <bits/stdc++.h>

using namespace std;

unsigned int opposite(unsigned int num)
{
    unsigned int op = 0;
    while(num!=0){
        op = op*10 + (num%10);
        num /= 10;
    }
    return op;
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        unsigned int num;
        scanf("%u", &num);
        for(int step = 0; ; step++){
            int opnum = opposite(num);
            if(opnum==num){
                printf("%d %u\n", step, opnum);
                break;
            }
            num += opnum;
        }
    }
}
