#include <bits/stdc++.h>

#define Read()            freopen("in.txt", "r", stdin)
#define Write()           freopen("out.txt", "w", stdout)
#define min3(a, b, c)     min(a, min(b, c))
#define max3(a, b, c)     max(a, max(b, c))
#define REP(i, a, b)      for(LL i = a; a<=b; i++)
#define FOR(i, a, b)      for(LL i = a; a<b; i++)
#define MEM(a, x)         memset(a, x, sizeof(a))
#define SQR(x)			  ((x)*(x))

#define pb   push_back
#define LL   long long
#define ULL  unsigned long long
#define MAX  10000000

using namespace std;

LL m, d, y;
LL im;
void impossible()
{
	if(!im) printf("%lld/%lld/%lld is an invalid date.\n", m, d, y);
	im = 1;
}

LL isleap(LL y)
{
	if(y<=1752) return !(y%4);
	else if(y%4 || (!(y%100) && y%400)) return 0;
	return 1;
}

string Months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string Days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
LL dpassed[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

LL dayno()
{
	LL x = ((y-1)*365 + dpassed[m-1] + d + (y-1)/4 + (isleap(y) && m>2));
	if(y>=1753) x = x - (y-1)/100 + (y-1)/400;
	return x;
}


int main(int argc, char const *argv[])
{
	//Read();
	//Write();
	while(scanf("%lld %lld %lld", &m, &d, &y) && (m||d||y)){
		im = 0;
		if((m<1 || m>12) || y<1) impossible();
		else if(m==2){
			if((isleap(y)) && (d>29 || d<1)) impossible();
			else if(!isleap(y) && (d>28||d<1))	impossible();
		}
		else if(m==4 || m==6 || m==9 || m==11){
			if(d>30||d<1) impossible();
		}
		if(d>31||d<1) impossible();


		LL dno = dayno();

		if(dno>=639799 && dno<=639809) impossible();
		if(dno>639809) dno -= 11;
		if(y>=1753) dno--;
		if(dno<0) dno += 7;
		if(!im) printf("%s %lld, %lld is a %s\n", Months[m-1].c_str(), d, y, Days[(dno-1)%7].c_str());
	}

	return 0;
}
