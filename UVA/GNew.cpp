#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000
char str[MAX];
struct info{
    int R,B,G,F_R,F_B,F_G;
    bool flag=false;
}Tree[MAX];

void Tree_check(int node){
    int lc=node<<1,rc=lc+1;
    Tree[node].R=Tree[lc].R+Tree[rc].R;
    Tree[node].G=Tree[lc].G+Tree[rc].G;
    Tree[node].B=Tree[lc].B+Tree[rc].B;
    Tree[node].F_G=Tree[lc].F_G+Tree[rc].F_G;
    Tree[node].F_B=Tree[lc].F_B+Tree[rc].F_B;
    Tree[node].F_R=Tree[lc].F_R+Tree[rc].F_R;
}

void build(int node,int l,int r){
    if(l==r){
        if(str[l-1]=='R'){
            Tree[node].R=1;
            Tree[node].B=Tree[node].G=Tree[node].F_B=Tree[node].F_G=Tree[node].F_R=0;
        }
        else if(str[l-1] == 'B'){
            Tree[node].B=1;
            Tree[node].R=Tree[node].G=Tree[node].F_B=Tree[node].F_G=Tree[node].F_R=0;
        }
        else {
            Tree[node].G=1;
            Tree[node].B=Tree[node].R=Tree[node].F_B=Tree[node].F_G=Tree[node].F_R=0;
        }
        Tree[node].flag=false;
        return;
    }
    int mid=(l+r)>>1,lc=node<<1,rc=lc+1;
    build(lc,l,mid);
    build(rc,mid+1,r);
    Tree_check(node);
}

void Lazy(int node,int l,int r){
    if(l < r){
        if(Tree[node].flag){
            int lc=node<<1,rc=lc+1;
            swap(Tree[lc].R,Tree[lc].B);
            swap(Tree[lc].G,Tree[lc].R);
            Tree[lc].F_R+=Tree[lc].R;
            Tree[lc].F_G+=Tree[lc].G;
            Tree[lc].F_B+=Tree[lc].B;
            Tree[lc].G=Tree[lc].B=Tree[lc].R=0;
            swap(Tree[rc].R,Tree[rc].B);
            swap(Tree[rc].G,Tree[rc].R);
            Tree[rc].F_R+=Tree[rc].R;
            Tree[rc].F_G+=Tree[rc].G;
            Tree[rc].F_B+=Tree[rc].B;
            Tree[rc].G=Tree[rc].B=Tree[rc].R=0;
            Tree[lc].flag=true;
            Tree[rc].flag=true;
            Tree[node].flag=false;

        }
    }
}

void update(int node,int l,int r,int i,int j){
    Lazy(node,l,r);
    if(l>=i && r<=j){
        swap(Tree[node].R,Tree[node].B);
        swap(Tree[node].G,Tree[node].R);
        Tree[node].F_R+=Tree[node].R;
        Tree[node].F_G+=Tree[node].G;
        Tree[node].F_B+=Tree[node].B;
        Tree[node].G=Tree[node].B=Tree[node].R=0;
        Tree[node].flag=true;
        return;
    }
    int mid=(l+r)>>1;
    int lc=node<<1,rc=lc+1;
    if(mid>=i && l <=j)update(lc,l,mid,i,j);
    if(r>=i && mid+1<=j)update(rc,mid+1,r,i,j);
    Tree_check(node);
}
int main(void)
{
    int num,light;
    scanf("%d%d",&num,&light);
    scanf("%s",str);
    build(1,1,num);
    for(int i=1;i<=light;i++){
        int l,r;
        scanf("%d%d",&l,&r);
        update(1,1,num,l,r);
        printf("%d %d %d\n",Tree[1].R+Tree[1].F_R, Tree[1].G+Tree[1].F_G , Tree[1].B+Tree[1].F_B);
    }

    return 0;
}
