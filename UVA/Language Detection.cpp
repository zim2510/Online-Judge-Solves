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
	// Read();
	// Write();

	int tc = 0;
	string x;
	while(cin>>x){
		if(x=="#") break;
		cout<<"Case "<<++tc<<": ";
		if(x=="HELLO") 	cout<<"ENGLISH"<<endl;
		else if(x=="HOLA") 	cout<<"SPANISH"<<endl;
		else if(x=="HALLO")  cout<<"GERMAN"<<endl;
		else if(x=="BONJOUR") cout<<"FRENCH"<<endl;
		else if(x=="CIAO") cout<<"ITALIAN"<<endl;
		else if(x=="ZDRAVSTVUJTE") cout<<"RUSSIAN"<<endl;
		else cout<<"UNKNOWN"<<endl;
	}

	return 0;
}