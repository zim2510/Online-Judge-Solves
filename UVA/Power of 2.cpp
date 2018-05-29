#include <stdio.h>

using namespace std;

int chk(long long int a);

int main()
{
    int t;
    scanf("%d", t);
    long long int nums[100000];
    for(int i = 0; i<t; i++){
        scanf("%d", nums[i]);
    }
    int count = 0;
    for(int i = 0; i<t; i++){
        for(int j = i+1; j<t; j++){
            if(chk(nums[i] + nums[j])) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}

inline int chk(long long int a)
{

        if(a & a- 1) return 0;
        return 1;
}
