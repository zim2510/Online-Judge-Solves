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

map<string, int> ids;
string in1[1005], in2[1005];
int it[1005];
string o1[1005], o2[1005];
int frnd[1005][1005];

int main(int argc, char const *argv[])
{
	Read();
	Write();
	int n, d, id = 1, cnt = 0;
	scanf("%d %d", &n, &d);
	for(int i = 0; i<n; i++){
		cin>>in1[i]>>in2[i]>>it[i];
		if(!ids[in1[i]]) ids[in1[i]] = id++;
		if(!ids[in2[i]]) ids[in2[i]] = id++;
	}

	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(in1[i]==in2[j] && in2[i]==in1[j]){
				if(it[j]-it[i]>0 && it[j]-it[i]<=d){
					if(frnd[ids[in1[j]]][ids[in2[j]]]==0){
						o1[cnt] = in1[j];
						o2[cnt] = in2[j];
						cnt++;
						frnd[ids[in1[j]]][ids[in2[j]]] = 1;
						frnd[ids[in2[j]]][ids[in1[j]]] = 1;
					}
				}
			}
		}
	}
	cout<<cnt<<endl;
	for(int i = 0; i<cnt; i++){
		cout<<o1[i]<<" "<<o2[i]<<endl;
	}

	return 0;
}