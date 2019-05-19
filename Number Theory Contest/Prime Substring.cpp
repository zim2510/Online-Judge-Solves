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
#define MAX               1000000000
#define ff                first
#define ss                second
#define sf             	  scanf
#define pf 	              printf

const int dx[] = { 0, -1,  0,  1,		 -1,  1,  1, -1,     -2, -2,  2,  2, -1, -1,  1,  1};
const int dy[] = {-1,  0,  1,  0,		  1,  1, -1, -1,     -1,  1, -1,  1, -2,  2, -2,  2};

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

vector <int> primes(100005);

void siv()
{
	for(int i = 4; i<100005; i+=2) primes[i] = 1;
	for(int i = 3; i*i<100005; i++){
		if(!primes[i]) for(int j = i*i; j<100005; j+=2*i){
			primes[j] = 1;
		}
	}
}

int str2num(string x)
{
	int num = 0;
	for(int i = 0; i<x.size(); i++){
		num = num*10 + x[i] - '0';
	}
	return num;
}

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	siv();
	string x;
	while(cin>>x && x!="0"){
		int mx = 0;
		for(int i = 0; i<x.size(); i++){
			for(int j = 1; j<=x.size() && j<6; j++){
				int temp = str2num(x.substr(i, j));
				if(!primes[temp] && temp>mx) mx = temp;
			}
		}
		cout<<mx<<endl;
	}
}