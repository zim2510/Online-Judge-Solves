#include <bits/stdc++.h>


using namespace std;

int main()
{
    int n, t = 0;
    while(scanf("%d", &n)==1){
        if(t++!=0) printf("\n");
        string names[n];
        map<string, int> net;
        for(int i = 0; i<n; i++){
            cin>>names[i];
            net[names[i]] = 0;
        }
        for(int i = 0; i<n; i++){
            string name;
            int total, cnt;
            cin>>name>>total>>cnt;
            for(int i = 0; i<cnt; i++){
                string get;
                cin>>get;
                net[get] += total/cnt;
                net[name] -= total/cnt;
            }
        }
        for(int i = 0; i<n; i++){
            cout<<names[i]<<" "<<net[names[i]]<<endl;
        }
    }
}
