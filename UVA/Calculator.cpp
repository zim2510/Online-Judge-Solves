#include <bits/stdc++.h>

using namespace std;

int main()
{
    double sg = 0, ct = 0, sw = 0, cw = 0;
    int sem;
    scanf("%d", &sem);
    for(int i = 0; i<sem; i++){
        printf("SG: ");
        scanf("%lf", &sg);
        printf("Weight: ");
        scanf("%lf", &sw);
        ct += sg*sw;
        cw += sw;
        printf("CG in Sem %d: %f\n", i+1, ct/cw);
    }
    return 0;
}
