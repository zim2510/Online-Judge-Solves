#include <bits/stdc++.h>

using namespace std;

string fib[500];

string sum(string a, string b){
	string c;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int i=0;
	int s=0;
	int lim=max(a.size(), b.size());
	while(i<lim){
		if(i<a.size()) s+=a[i]-'0';
		if(i<b.size()) s+=b[i]-'0';
		c+=(s%10+'0');
		s/=10;
		i++;
	}
	while(s){
		c+=(s%10+'0');
		s/=10;
	}
	reverse(c.begin(), c.end());
	return c;
}

void dp()
{
    fib[2] = "2";
    fib[1] = "1";
    for(int i = 3; ; i++){
        fib[i] = sum(fib[i-1], fib[i-2]);
        //printf("%d: %s\n", i, fib[i].c_str());
        if(fib[i].size()>100){
            break;
        }
    }
}

bool greatr(string a, string b)
{
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    else return a>=b;
}

bool greatr2(string a, string b)
{
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    else return a>b;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    dp();
    string sp, ep;

    while(1){
        cin>>sp>>ep;
        if(sp != "0" || ep != "0"){
            int s, e;
            for(int i = 0; i<481; i++){
                if(greatr(fib[i], sp)){
                    s = i;
                    //printf("%s %d\n", fib[i].c_str(), i);
                    break;
                }
            }
            for(int i = 0; i<481; i++){
                if(greatr2(fib[i], ep)){
                    e = i;
                    //printf("%s %d\n", fib[i].c_str(), i);
                    break;
                }
            }
            printf("%d\n", e-s);
        }

        else break;
    }
}
