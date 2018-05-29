#include <bits/stdc++.h>

using namespace std;

map <int, int> pile, plate;
vector <int> v[209];

void changePlateState(int p, int x, int y){
    int i, j, k;
    int xx, yy;
    xx = pile[p]; pile[p] = x;
    yy = plate[p]; plate[p] = y;

    int len = v[xx].size();
    for( i=yy-1 ; i<len-1 ; i++ ){
        v[xx][i] = v[xx][i+1];
        k = v[xx][i];
        plate[k] = (i-1) + 1;
    }
    v[xx].pop_back();
    v[x].push_back(0);
    len = v[x].size();
    for( i=len-1 ; i>=y ; i-- ){
        k = v[x][i-1];
        v[x][i] = k;
        plate[k] = i + 1;
    }
    v[x][y-1] = p;
    return;

}

int main(){

   freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);

    int i, j, k, n, m, q, num, test, kase = 0;
    cin >> test;
    while(test--){
        char op;
        int p, x, y;
        cin >> n >> m >> q;

        for( i=0 ; i<n ; i++ ){
            cin >> num;
            for( j=0 ; j<num ; j++ ){
                cin >> k;
                v[i+1].push_back(k);
                pile[k] = i+1;
                plate[k] = j+1;
            }
        }

        for( i=0 ; i<q ; i++ ){
            cin >> op;
            if( op=='C' ){
                cin >> p >> x >> y;
                changePlateState(p, x, y);
            }
            else {
                cin >> p;
                cout << pile[p] << " " << plate[p] << endl;
            }
        }

        pile.clear();
        plate.clear();
        memset(v, 0, sizeof v);
    }

    return 0;
}
