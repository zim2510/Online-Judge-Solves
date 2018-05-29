#include <bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	scanf("%d", &tc);
	for(int i = 1; i<=tc; i++){
		double ah, al, bh, bl, bx, ch;
		double tarea, atri;
		scanf("%lf %lf %lf %lf %lf", &ah, &al, &bh, &bl, &bx);
		double sidea, sideb, sidec, perim;

		ch = al + bl;
		perim = (ah + bh + ch)/2;
		atri = sqrt(perim*(perim-ah)*(perim-bh)*(perim-ch));
		tarea = atri * 6;

		double th = 2*acos((ah*ah + ch*ch - bh*bh)/(2*ah*ch));
		double larea = .5*th*al*al;

		th = 2*acos((bh*bh + ch*ch - ah*ah)/(2*bh*ch));

		tarea += (3*(.5*(2*PI-th)*bl*bl));
		tarea -= (4*(PI*bx*bx) + 3*larea);
		printf("Case %d: %d\n", i, (int)tarea);
	}

}