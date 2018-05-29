#include <stdio.h>

int main()
{
    int i, h1, h2, m1, m2, s1, s2, unit;

    scanf("%d", &i);
    getchar();

    while(i--){
        scanf("%d %d %d", &h1, &m1, &s1);
        getchar();
        scanf("%d %d %d", &h2, &m2, &s2);
        getchar();
        scanf("%d", &unit);
        getchar();

        if(s2>=s1) s2=s2-s1;
        else if(s2<s1) {s2=s2+60-s1; m2--;}

        if(m2>=m1) m2=m2-m1;
        else if(m2<m1) {m2=m2+60-m1; h2--;}

        if(h2>=h1) h2=h2-h1;
        else if(h2<m1) {h2=h2+24-h1;}

        unit=unit*((h2*3600)+(m2*60)+s2);

        printf("%d\n", unit);
    }

    return 0;
}


