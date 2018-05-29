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

map <char, bool> good;

bool isnotsame(char a, char b)
{
	if(a==b) return 0;
	if(a==b+'A'-'a') return 0;
	if(a==b-'A'+'a') return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	Read();
	Write();
	string gd;
	cin>>gd;
	for(int i = 0; i<gd.size(); i++){
		good[gd[i]] = 1;
	}
	string pattern;
	cin>>pattern;
	int n;
	scanf("%d", &n);
	for(int i = 0; i<n; i++){
		int p = 1;
		string in;
		cin>>in;
		int j = 0;
		for(int i = 0; i<in.size() && j<pattern.size() && p; i++, j++){
			if(isnotsame(in[i], pattern[j])){
				if(pattern[i]=='?'){
					if(!good[in[i]]){
						p = 0;
						break;
					}
				}
				else if(pattern[j]=='*'){
					if(in.size()<pattern.size()){
						if(pattern.size()-in.size()>=2){
							p = 0;
							break;
						}	
						else i -= 1;
					}
					else if(in.size()>pattern.size()){
						for(int x = i; x<i+(in.size()-pattern.size()); x++){
							if(good[in[x]]){p = 0; break;}
						}
						i += in.size()-pattern.size();
					}
					else if(good[in[i]]){ p = 0; break;}
				}
				else{
					p = 0;
					break;
				}
			}
		}
		if(p) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}