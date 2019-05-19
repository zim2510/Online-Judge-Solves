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

struct process{
	int pid, priority, at, bt;
	int wt, tat, ft;
};

bool cmpbyat(process a, process b){ return a.at<b.at; }
bool cmp(process a, process b){
	if(a.priority!=b.priority) return a.priority<b.priority;
	else return a.at<b.at;
}
bool cmpbyid(process a, process b) { return a.pid<b.pid; }

int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	pf("Please enter the no of processes:\n");
	int n;
	sf("%d", &n);

	vector <process> pcs(n);
	map<int, int> m;


	FOR(i, 0, n){
		printf("Input data for process %d in format: <process_id> <priority> <arrival_time> <burst_time>\n", i+1);
		scanf("%d %d %d %d", &pcs[i].pid, &pcs[i].priority, &pcs[i].at, &pcs[i].bt);
	}
	sort(pcs.begin(), pcs.end(), cmpbyat);
	FOR(i, 0, n){
		m[pcs[i].pid] = i;
	}

	vector <process> queue;

	for(int time = 0, i = 0, ended = 0; ended<n; time++){
		if(i<n && time>=pcs[i].at){;
			queue.pb(pcs[i]);
			i++;
		}
        sort(queue.begin(), queue.end(), cmp);
		if(queue.size()) queue[0].bt--;
		if(queue.size() && queue[0].bt==0){
			pcs[m[queue[0].pid]].ft = time+1;
			queue.erase(queue.begin());
			ended++;
		}
	}

	FOR(i, 0, n){
		pcs[i].tat = pcs[i].ft - pcs[i].at;
		pcs[i].wt = pcs[i].tat - pcs[i].bt;
	}

	sort(pcs.begin(), pcs.end(), cmpbyid);
	
	int totalwt = 0;
	FOR(i, 0, 3) printf("\n");
	FOR(i, 0, n){
		printf("Process id: %d Finish time: %d TAT: %d WT: %d\n", pcs[i].pid, pcs[i].ft, pcs[i].tat, pcs[i].wt);
		totalwt += pcs[i].wt;
	}
	printf("Average WT: %d\n", totalwt/n);

}
