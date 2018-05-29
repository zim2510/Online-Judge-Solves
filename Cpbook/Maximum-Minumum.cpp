#include <iostream>
using namespace std;

int findmaximum(int a, int b, int c, int d, int e);

int findminimum(int a, int b, int c, int d, int e);

int main()
{
    int lines, i;
    int a, b, c, d, e;

    cin>>lines;

    for(i=0; i<lines; i++){
        cin>>a>>b>>c>>d>>e;
        cout<<findmaximum(a,b,c,d,e)<<" "<<findminimum(a,b,c,d,e)<<endl;
   }

    return 0;
}

int findmaximum(int a, int b, int c, int d, int e)

{
    int init;
    init=-1000;
    if(a>init) init=a;
    if(b>init) init=b;
    if(c>init) init=c;
    if(d>init) init=d;
    if(e>init) init=e;
    return init;
}

int findminimum(int a, int b, int c, int d, int e)

{
    int init;
    init=a;
    if(a<init) init=a;
    if(b<init) init=b;
    if(c<init) init=c;
    if(d<init) init=d;
    if(e<init) init=e;
    return init;
}
