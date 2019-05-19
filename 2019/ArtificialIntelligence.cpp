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

bool check(int N,int pos)	{ return (bool)(N & (1<<pos)); }
int sset(int N,int pos)		{	return N=N | (1<<pos);	   }

double P = -1, I = -1, U = -1;

void parse(string x, int sp)
{
	int value = 0, div = 0, neg = x[sp+2]=='-';

	for(int i = sp + 2 + neg; i<x.size(); i++){
		if(valid(x[i], '0', '9')) value = value * 10 + x[i] - '0', div *= 10;
		else if(!div && x[i]=='.') div = 1;
		else if(x[i]=='m') { div = div?div*1000:1000; break;}
		else if(x[i]=='k') { value *= 1000; break;}
		else if(x[i]=='M') { value *= 1000000; break;}
		else break;
	}

	if(neg) value *= -1;
	
	if(x[sp]=='P') P = div?(double)value/div:value;
	else if(x[sp]=='I') I = div?(double)value/div:value;
	else if(x[sp]=='U') U = div?(double)value/div:value;
}

void calculate()
{
	if(P==-1) printf("P=%0.2lfW\n\n", U*I);
	else if(I==-1) printf("I=%0.2lfA\n\n", P/U);
	else if(U==-1) printf("U=%0.2lfV\n\n", P/I);
}

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int tc;
	sf("%d ", &tc);

	TC(i, 1, tc){
		P = I = U = -1;
		string x;
		getline(cin, x);

		for(int i = 0; i<x.size(); i++){
			if(x[i]=='=') parse(x, i-1);
		}

		cout<<"Problem #"<<i<<endl;
		calculate();
	}
}
