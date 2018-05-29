#include <iostream>
#include<cmath>

using namespace std;

int findif(int a);


int main()
{
    int lines, i;
    int a;

    cin>>lines;

    for(i=0; i<lines; i++){
        cin>>a;
        if(findif(a)==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
   }

    return 0;
}

int findif(int a)

{
    int init;
    init=sqrt(a);
    if(init*init==a) return 1;
    return 0;
}
