#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define TC(i, a, b)       for(int i = a; i<=b; i++)
#define FOR(i, a, b)      for(int i = a; i<b; i++)
#define ROF(i, a, b)      for(int i = a; i>=b; i--)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)            ((x)*(x))
#define valid(x, s, e)    (x>=s && x<=e)
#define sz(a)             int((a).size()) 
#define all(c)            (c).begin(),(c).end() 
#define tr(c,i)           for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x)      ((c).find(x) != (c).end()) 
#define cpresent(c,x)     (find(all(c),x) != (c).end()) 
#define pb                push_back
#define MAX               10000000000
#define ff                first
#define ss                second
#define sf             	  scanf
#define pf 	              printf

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

bool str2num(string num, int base)
{
	LL number = 0;
	for(int i = 0; i<num.size(); i++){
		if(num[i]-'0'>=base) return 0;
		number = number*base + num[i]-'0';
	}
	LL x = sqrt(number)+0.00001;
	return number==x*x;
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	string x;
	while(cin>>x){
		if(x=="0") break;
		for(int i = 2; i<=100; i++){
			if(str2num(x, i)){
				cout<<i<<endl;
				break;
			}
		}
	}
}