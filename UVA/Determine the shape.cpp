#include <bits/stdc++.h>

using namespace std;

struct point
{
    int x, y;
};

point points[4];


int squaredis(point a, point b)
{
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

bool leftorder(point a, point b)
{
    if(a.x<b.x) return 1;
    else if(a.x>b.x) return 0;
    if(a.y<b.y) return 1;
    else return 0;
}

bool diagonalBisect()
{
    return ((points[0].x+ points[2].x == points[1].x+ points[3].x) && (points[0].y+ points[2].y == points[1].y+ points[3].y));
}

bool diagonalEqual()
{
    return squaredis(points[0], points[1]) == squaredis(points[1], points[3]);
}

bool adjacentEqual()
{
    return squaredis(points[0], points[1]) == squaredis(points[0], points[3]);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for(int i = 1; i<=tc; i++){
        for(int i = 0; i<4; i++) scanf("%d %d", &points[i].x, &points[i].y);
        sort(points, points+4, leftorder);
        sort(points+1, points+4, angle(points[0]));

        printf("Case %d: ", i);

        if(diagonalBisect()){
            if(adjacentEqual()){
                if(diagonalEqual()) printf("Square\n");
                else printf("Rhombus\n");
            }
            else{
                if(diagonalEqual()) printf("Rectangle\n");
                else printf("Parallelogram\n");
            }
        }

        else printf("Ordinary Quadrilateral\n");
    }
}
