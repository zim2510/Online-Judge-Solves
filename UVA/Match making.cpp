#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n, tc = 0;
    while(scanf("%d", &n) && n){
        vector <int> ase(256), nai(256);
        map <char, bool> mark;
        vector <char> ignore;
        string x, y;
        bool possible = 1;
        char last = '0';
        for(int i = 0; i<n; i++){
            cin>>x>>y;
            int diff = x.size()-y.size();
            if(diff<0) possible = 0;
            for(int i = 1; i<y.size()-1; i++){
                if(y[i]>last) last = y[i];
                ase[y[i]] = 1;
                if(y[i]!=x[i]) possible = 0;
            }
            nai[x[y.size()-1]] = 1;
        }
        for(int i = 0; i<256; i++){
            if(ase[i] && nai[i]) possible = 0;
        }
        
        if(nai[last]) for(char i = '0'; i<='9'; i++) if(!nai[i]) {last = i; break;} 
        if(nai[last]) for(char i = 'A'; i<='Z'; i++) if(!nai[i]) {last = i; break;} 
        if(nai[last]) for(char i = 'a'; i<='z'; i++) if(!nai[i]) {last = i; break;} 
        if(nai[last]) possible = 0;
        
        printf("Case %d: ", ++tc);
        if(possible){
            printf("[");
            for(char i = '0'; i<=last && i<='9'; i++) if(!nai[i]) printf("%c", i);
            for(char i = 'A'; i<=last && i<='Z'; i++) if(!nai[i]) printf("%c", i);
            for(char i = 'a'; i<=last && i<='z'; i++) if(!nai[i]) printf("%c", i);
            printf("]");
        }
        else printf("I_AM_UNDONE");
        printf("\n");
    }
}