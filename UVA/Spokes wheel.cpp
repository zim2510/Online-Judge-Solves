#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        long long int strt, fnsh;
        scanf("%x %x", &strt, &fnsh);

        char before[33], after[33];
        before[32] = after[32] = '\0';

        for(int i = 0; i<32; i++){
            before[i] = '0' + strt%2;
            strt /= 2;
        }

        for(int i = 0; i<32; i++){
            after[i] = '0' + fnsh%2;
            fnsh /= 2;
        }
        //printf("%s %s\n", before, after);

        int right = -1, left = -1;
        char neww[33];
        neww[32] = '\0';

        for(int i = 0; i<32; i++){
            for(int j = 0; j<32; j++){
                neww[j] = before[(j+i)%32];
            }
            //printf("%s %s\n", neww, after);
            if(strcmp(neww, after)==0){
                right = i;
                break;
            }
        }
        for(int i = 0; i<32; i++){
            for(int j = 0; j<32; j++){
                neww[j] = after[(j+i)%32];
            }
            //printf("%s %s\n", neww, after);
            if(strcmp(neww, before)==0){
                left = i;
                break;
            }
        }


        printf("Case #%d: ", i);
        if(left==right && left != -1) printf("%d Any\n", left);
        else if(left==right && left==-1) printf("Not possible\n");
        else if(right>16) printf("%d Left\n", 32-right);
        else if(right<16) printf("%d Right\n", right);

    }
}
