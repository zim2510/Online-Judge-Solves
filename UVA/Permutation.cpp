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
	//Read();
	//Write();
	string in;
	cin>>in;
	int cnt = 1;
	int on = 1;
	for(int i = 1; i<in.size(); i++){
		if(on==5 || in[i]!=in[i-1]){
			cnt++;
			on = 1;
		}
		else on++;
	}
	printf("%d\n", cnt);
}