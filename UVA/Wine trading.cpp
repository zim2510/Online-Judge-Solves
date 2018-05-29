#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mnt[100000];
    while(1){
        int n;
        long long cnt = 0;
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i<n; i++) scanf("%d", &mnt[i]);
        for(int i = 0; i<n-1; i++){
            if(!mnt[i]) continue;
            for(int j = i+1; j<n; j++){
                if(!mnt[i]) break;
                if(!mnt[j]) continue;

                if(mnt[i]>0 && mnt[j]<0){
                    if(abs(mnt[i])>abs(mnt[j])){
                        cnt += (abs(mnt[j])) * (j-i);
                        //printf("%d %d %d\n", cnt, mnt[i], mnt[j]);
                        mnt[i] -= abs(mnt[j]);
                        mnt[j] = 0;
                    }
                    else if(mnt[i]<=abs(mnt[j])){
                        cnt += mnt[i] * (j-i);
                        //printf("%d %d %d\n", cnt, mnt[i], mnt[j]);
                        mnt[j] = mnt[i] + mnt[j];
                        mnt[i] = 0;
                    }
                }

                else if(mnt[i]<0 && mnt[j]>0){
                    if(abs(mnt[i])>mnt[j]){
                        cnt += (abs(mnt[j])) * (j-i);
                        mnt[i] += abs(mnt[j]);
                        mnt[j] = 0;
                    }
                    else if(abs(mnt[i])<=abs(mnt[j])){
                        cnt += abs(mnt[i]) * (j-i);
                        mnt[j] = mnt[i] + mnt[j];
                        mnt[i] = 0;
                    }
                }
            }
        }
        printf("%lld\n", cnt);

    }
}
