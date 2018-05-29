#include <bits/stdc++.h>

using namespace std;

int main()
{
    char in[19];
    int counter = 0;
    scanf("%s", in);
    for(int i = 0; in[i]!='\0'; i++){
        if(in[i]=='4' || in[i]=='7') counter++;
    }
    printf("%d", counter);
    while(counter){
        if(counter%10==4 || counter%10==7){
            counter /= 10;
        }
        else{
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

}
