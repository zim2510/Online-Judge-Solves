#include <iostream>
using namespace std;

int findaverage(int a, int b, int c, int d, int e);


int main()
{
    int lines, i;
    int a, b, c, d, e;

    cin>>lines;

    for(i=0; i<lines; i++){
        cin>>a>>b>>c>>d>>e;
        cout<<findaverage(a,b,c,d,e)<<endl;
   }

    return 0;
}

int findaverage(int a, int b, int c, int d, int e)

{
    int init;
    init=a+b+c+d+e;
    return init/5;
}

