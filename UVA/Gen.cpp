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
	int a, b, c, d, e, f, g, h;
	for(int a = 0; a<=100; a++){
		for(int b = 0; b<=100; b++){
			for(int c = 0; c<=100; c++){
				for(int d = 0; d<=100; d++){
					for(int e = 0; e<=100; e++){
						for(int f = 0; f<=100; f++){
							for(int g = 0; g<=100; g++){
								for(int h = 0; h<=100; h++){
									printf("%d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h);
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}