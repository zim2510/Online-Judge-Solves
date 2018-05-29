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
	Read();
	Write();
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		int f, e, s, ep, pos = 0;
		scanf("%d %d %d %d", &f, &e, &s, &ep);
		if(s>ep) swap(s, ep);
		for(int i = 0; i<e; i++){
			int sp, in;
			scanf("%d %d", &in, &sp);
			if(!pos){
				if(sp<=s){
					if((s-sp)%in==0 && (ep-sp)%in==0){
						pos = 1;
						printf("%d %d\n", sp, in);
					}
				}
			}
		}
		if(pos) printf("It is possible to move the furniture.\n");
		else printf("The furniture cannot be moved.\n");
	}

	return 0;
}