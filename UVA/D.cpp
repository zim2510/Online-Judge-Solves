#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define MAX 1000000

ll D[MAX];
ll sum[MAX];
int a[MAX];
ll RevSum[MAX];
int main(void)
{
    int num;
    scanf("%d",&num);
    D[1]=0;
    sum[1]=0;
    for(int i=1;i<=num;i++){
        scanf("%d",&a[i]);
        D[i+1]=D[i]+a[i];
        sum[i+1]=sum[i]+D[i+1];
    }
    RevSum[num]=a[num];
    ll temp=0;
    for(int i=num-1;i>=1;i--){
        temp+=a[i];
        RevSum[i]=RevSum[i+1]+temp;
    }
    for(int i=1;i<=num+1 ;i++)cout<<sum[i]<<" sum D "<<D[i]<<" pos "<<i<<endl;
    ll ans=0;
    for(int i=1;i<num;i++){
        int low=i,hi=num,pos=i;
        while(low<=hi){
            int mid=(low+hi)>>1;
            ll LineDis=D[mid]-D[i];
            ll ReverseDis=D[i] + a[num] + D[num]-D[mid];
            if(LineDis <= ReverseDis){
                pos=mid;
                low=mid+1;
            }
            else hi=mid-1;
        }
        ans+=sum[pos]-sum[i];
        ans+=sum[i]+RevSum[pos];
        cout<<" For "<<i <<" pos  "<<pos<<endl;
    }
    printf("%lld\n",ans);

    return 0;
}
