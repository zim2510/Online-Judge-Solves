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

bool isPalindrome(string x)
{
	string y = x;
	reverse(all(y));
	return x==y;
}

bool isMirror(string x)
{
	map<char, char> M;
	
	M['A'] = 'A';
	M['E'] = '3';
	M['H'] = 'H';
	M['I'] = 'I';
	M['J'] = 'L';
	M['L'] = 'J';
	M['M'] = 'M';
	M['O'] = 'O';
	M['S'] = '2';
	M['T'] = 'T';
	M['U'] = 'U';
	M['V'] = 'V';
	M['W'] = 'W';
	M['X'] = 'X';
	M['Y'] = 'Y';
	M['Z'] = '5';
	M['1'] = '1';
	M['2'] = 'S';
	M['3'] = 'E';
	M['5'] = 'Z';
	M['8'] = '8';

	int start = 0, end = x.size()-1;

	while(start<=end){
		if(M[x[start]]!=x[end]) return false;
		start++, end--;
	}

	return true;
}


int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		printf("J^2\n");
	#endif
	
	string x;
	
	while(cin>>x){

		bool palindrome = isPalindrome(x), mirror = isMirror(x);

		if(palindrome && mirror){
			cout<<x<<" -- is a mirrored palindrome.";
		}
		else if(palindrome){
			cout<<x<<" -- is a regular palindrome.";
		}
		else if(mirror){
			cout<<x<<" -- is a mirrored string.";
		}
		else{
			cout<<x<<" -- is not a palindrome.";
		}

		cout<<endl<<endl;
	}
}
