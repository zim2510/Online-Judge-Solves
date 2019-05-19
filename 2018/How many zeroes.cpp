#include <bits/stdc++.h>
 
using namespace std;
 
 
long long opt[50][2][2];
 
long long getCount(string in, int pos, int tight)
{
    if(tight==1){
        long long sum = 0;
        for(int i = pos+1; i<in.size(); i++){
            sum = sum*10 + in[i] - '0';
        }
        return max(sum+1, (long long)1);
    }
 
    else{
        long long sum = 1;
        for(int i = 0; i<in.size()-pos-1; i++) sum *= 10;
        return max(sum, (long long)1);
    }
}
 
long long dp(string in, int index, int tight, int allzero)
{
    //cout<<"Got in "<<index<<" "<<tight<<" "<<allzero<<endl;
    if(index==in.size()) return 0;
    if(opt[index][tight][allzero]!=-1) return opt[index][tight][allzero];
    int k = (tight==1)?in[index]-'0':9;
    for(int i = 0; i<=k; i++){
        if(i==0){
            if(allzero){
                opt[index][tight][allzero] = 0;
                opt[index][tight][allzero] += dp(in, index+1, tight && i==k, 1);
            }
            else{
                opt[index][tight][allzero] = 0;
                opt[index][tight][allzero] = getCount(in, index, tight && k==i) + dp(in, index+1, tight && i==k, allzero);
            }
        }
        else opt[index][tight][allzero] += dp(in, index+1, tight && i==k, 0);
    }
    //cout<<"Getting out "<<index<<" "<<tight<<" "<<allzero<<": "<<opt[index][tight][allzero]<<endl;
    return opt[index][tight][allzero];
}
 
int zeros(string in)
{
    int cnt = 0;
    for(int i = 0; i<in.size(); i++) if(in[i]=='0') cnt++;
    //cout<<cnt<<endl;
    return cnt;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
 
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++){
        string start, end;
        cin>>start>>end;
        memset(opt, -1, sizeof(opt));
        long long x = dp(start, 0, 1, 1);
        //cout<<x<<endl;
        memset(opt, -1, sizeof(opt));
        long long y = dp(end, 0, 1, 1);
        //cout<<y<<endl;
 
        cout<<"Case "<<i<<": "<<y-x+zeros(start)<<endl;
 
    }
}