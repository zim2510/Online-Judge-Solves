#include<bits/stdc++.h>
using namespace std;
int DP[3000006];
int PT[3000006];
int n;

void pathPrint(int pos){
	if(pos==1){
		printf("1");
		return;
	}
	pathPrint(PT[pos]);
	printf(" %d", pos);
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    while(scanf("%d", &n) == 1){
    memset(DP, 121, sizeof(DP));
    DP[1]=0;
    for(int i=1; i<=n; i++){
    	if(DP[i]+1<DP[i*3]){
    		DP[i*3]=DP[i]+1;
    		PT[i*3]=i;
    	}
    	if(DP[i]+1<DP[i*2]){
    		DP[i*2]=DP[i]+1;
    		PT[i*2]=i;
    	}
    	if(DP[i]+1<DP[i+1]){
    		DP[i+1]=DP[i]+1;
    		PT[i+1]=i;
    	}
    }
    printf("%d\n", DP[n]);
    pathPrint(n);
    printf("\n");
    }
    return 0;
}
