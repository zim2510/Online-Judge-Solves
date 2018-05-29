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

using namespace std;


typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii;
typedef long long LL;
typedef unsigned long long ULL;

map<int, bool> isThere;
map<int, LL> words;
vector <int> ids;
int top = 0, cnt = 0;

void add()
{
	int id;
	scanf("%d", &id);
	if(!isThere[id]){ 
		printf("success.\n"); 
		isThere[id] = 1;
		ids.pb(id); 
		words[id] = 0; 
	}
	else printf("same priority.\n");
}

void close()
{
	int id;
	scanf("%d", &id);
	if(isThere[id]){ 
		printf("close %d with %lld.\n", id, words[id]);
		if(id==top) top = 0;
		isThere[id] = 0;
		words[id] = 0;
		for(int i = 0; i<ids.size(); i++){
			if(ids[i]==id){
				ids.erase(ids.begin()+i);
				break;
			}
		}
	}
	else printf("invalid priority.\n");
}

void chat()
{
	int w;
	scanf("%d", &w);
	if(top) { words[top] += w; printf("success.\n"); }
	else if(ids.empty()) printf("empty.\n");
	else { words[ids[0]] += w; printf("success.\n"); }
}

void rotate()
{
	int n, mx;
	scanf("%d", &n);
	if(n<1 || n>ids.size()){
		printf("out of range.\n");
		return;
	}
	printf("success.\n");
	mx = ids[n-1];
	for(int i = n-1; i>=1; i--){
		ids[i] = ids[i-1];
	}
	ids[0] = mx;
}
void prior()
{
	if(ids.empty()){
		printf("empty.\n");
		return;
	}
	printf("success.\n");
	int mx = 0, pos;
	for(int i = 0; i<ids.size(); i++){
		if(ids[i]>mx){
			mx = ids[i];
			pos = i;
		}
	}
	for(int i = pos; i>=1; i--){
		ids[i] = ids[i-1];
	}
	ids[0] = mx;
}
void choose()
{
	int id;
	scanf("%d", &id);
	int pos = -1;
	for(int i = 0; i<ids.size(); i++){
		if(ids[i]==id){
			pos = i;
			break;
		}
	}
	if(pos==-1){ printf("invalid priority.\n"); return; }
	printf("success.\n");
	for(int i = pos; i>=1; i--){
		ids[i] = ids[i-1];
	}
	ids[0] = id;
}
void Top()
{
	int n;
	scanf("%d", &n);
	if(isThere[n]) { top = n; printf("success.\n"); }
	else printf("invalid priority.\n");
}
void Untop()
{
	if(top){ top = 0; printf("success.\n");}
	else printf("no such person.\n");
}
void Bye()
{
	if(top && words[top]) printf("Bye %d: %lld\n", top, words[top]);
	for(int i = 0; i<ids.size(); i++){
		if(words[ids[i]] && ids[i]!=top) printf("Bye %d: %lld\n", ids[i], words[ids[i]]);
	}
}
int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	int tc;
	scanf("%d", &tc);

	TC(i, 1, tc){
		isThere.clear(), ids.clear(), words.clear();
		top = 0, cnt = 0;


		string cmd;
		int commands;
		scanf("%d", &commands);


		for(int i = 0; i<commands; i++){
			printf("Operation #%d: ", ++cnt);
			cin>>cmd;
			if(cmd=="Add") add();
			else if(cmd=="Close") close();
			else if(cmd=="Chat") chat();
			else if(cmd=="Rotate") rotate();
			else if(cmd=="Prior") prior();
			else if(cmd=="Choose") choose();
			else if(cmd=="Top") Top();
			else if(cmd=="Untop") Untop();
		}
		Bye();
	}
}