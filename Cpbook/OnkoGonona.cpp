#include <iostream>
using namespace std;


int findresult(int a);


int main()
{
    int lines, i, a;

    cin>>lines;

    for(i=0; i<lines; i++){
        cin>>a;
        cout<<findresult(a)<<endl;
   }

    return 0;
}

int findresult(int a)
{
    int init;
    if(a==0) return 1;
    for(init=0;a>0;init++){
        a=a/10;
    }
    return init;

}

