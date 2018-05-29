#include <stdio.h>


int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) && (a || b)){
        int c = 0, cnt = 0;
        while(a || b){
            if(a%10 + b%10 + c > 9){
                c = 1;
                cnt++;
            }
            else c = 0;
            a /= 10;
            b /= 10;
        }
        if(cnt>1) printf("%d carry operations.\n", cnt);
        else printf("%s carry operation.\n", cnt==1?"1":"No");
    }
}
