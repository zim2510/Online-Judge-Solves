#include <stdio.h>
#include <string.h>
struct player
{
    char name[100];
    int age;
    double bavg;
};

int main()
{
    struct player p1;
    strcpy(p1.name, "Shakib");
    p1.age = 25;
    p1.bavg = 9.8;

    printf("%s %d %lf\n", p1.name, p1.age, p1.bavg);
}

/*void SieveOfEratosthenes(int n)
{

    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

}
*/
