#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int lines;
    cin>>lines;
    for(int i=0; i<lines; i++){
        float a, b, c;
        cin>>a>>b>>c;
        if(c>300) break;
        float present=b/(300-c)*6;
        float required=6*(a-b+1)/c;
        printf("%.2f %.2f\n",present, required);
    }
}
