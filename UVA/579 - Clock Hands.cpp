#include <bits/stdc++.h>
int main(){
    int h, m;
    while(scanf("%d:%d", &h, &m)==2 && (h||m)){
        double hdeg = h*30.0 + (m*.5);
        double mdeg = m*6.0;
        double diff = std::max(hdeg, mdeg) - std::min(hdeg, mdeg);
        if(diff>180) diff = 360 - diff;
        printf("%0.3lf\n", diff);
    }
}
