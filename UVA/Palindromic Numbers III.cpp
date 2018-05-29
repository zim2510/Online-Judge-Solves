#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(int i = a; a<=b; i++)
#define FOR(i, a, b)      for(int i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		string in;
		int flag1 = 0, flag2 = 0;
		cin>>in;
		int n = in.size();
		cout<<"Case "<<i<<": ";

		for(int i = 0; i<=(n-1)/2; i++){
			//printf("HERE1\n");
			if(in[i]>in[n-1-i]){
                //printf("%d %d ", in[i]-'0', in[n-1-i]-'0');
				in[in.size()-1-i] = in[i];
				flag1 = 1;
			}
			if(flag1 && in[i]<in[n-1-i]) flag1 = 0;
		}
        //printf("%d %d ", flag1, (n-1)/2);
		if(!flag1) for(int i = (n-1)/2; i>=0; i--){
			//printf("HERE2\n");
			if(in[i]<'9'){
				in[i]++;
                for(int x = i+1; x<=(n-1)/2; x++) in[x] = '0';
				//printf("I%d", in[i]-'0');
				flag2 = 1;
				break;
			}
		}
       // printf("%d %d\n", n-1, (n-1)/2);
		for(int i = n-1; i>=(n-1)/2; i--){
			//printf("%d %d HERE3\n", (n-1)/2, i);
			in[i] = in[n-1-i];
		}

		if(!flag1 && !flag2){
			cout<<1;
			for(int i = 0; i<=n-2; i++) cout<<0;
			cout<<1<<endl;
		}
		else cout<<in<<endl;
	}

	return 0;
}
