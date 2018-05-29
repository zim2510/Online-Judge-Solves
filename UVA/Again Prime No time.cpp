#include <bits/stdc++.h>

#define Read() freopen("in.txt", "r", stdin)
#define Write() freopen("out.txt", "w", stdout)
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define REP(i, a, b) for(int i = a; i<=b; i++)
#define FOR(i, a, b) for(int i = a; i<b; i++)
#define MEM(a, x) memset(a, x, sizeof(a))

#define pb push_back
#define LL long long
#define ULL unsigned long long
#define MAX 10000


int prime[MAX], primes[78500], ncnt[1000000];

using namespace std;

void siv()
{
	for(int i = 4; i<MAX; i+=2) prime[i] = 1;
	for(int i = 3; i*i<MAX; i+=2){
		if(!prime[i]) for(int x = i*i; x<MAX; x+=2*i){
			prime[x] = 1;
		}
	}
	int x = 0;
	primes[x++] = 2;
	for(int i = 3; i<MAX; i+=2){
		if(!prime[i]) primes[x++] = i;
	}
}

int mfct[5000];

int main()
{
	siv();
	// Read();
	// Write();

	int tc;
	scanf("%d", &tc);

	REP(i, 1, tc){
		int m, n, pos = 1;
		scanf("%d %d", &m, &n);
		printf("Case %d:\n", i);
		MEM(mfct, 0);

		int x = m;
		for(int i = 0; primes[i]<=m; i++){
            mfct[i] = 0;
			if(m%primes[i]==0){
				while(m%primes[i]==0){
					mfct[i]++;
					m /= primes[i];
				}
			}
		}

		int mn = INT_MAX;
        for(int i = 0; primes[i]<=x; i++){
            if(mfct[i]){
                int z = n, cnt = 0;
                while(z){
                    cnt += z/primes[i];
                    z /= primes[i];
                }
                if(cnt<mfct[i]) mn = 0;
                else mn = min(mn, cnt/mfct[i]);

            }
        }
        if(mn) printf("%d\n", mn);
        else printf("Impossible to divide\n");
	}
}
