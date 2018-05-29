#include <bits/stdc++.h>

using namespace std;

int power(int n)
{
    int x = 1;
    for(int i = 1; i<=n; i++) x = x*2;
    return x;
}


void heapify(int *heap, int heapsize)
{

    while(1){
        int sp = power(log(heapsize))-1;
        printf("%d %d\n", heapsize, sp);
        int count = 0;
        for(int i = sp; i>0; i--){
            if(heap[i*2]>heap[i]) swap(heap[i*2], heap[i]), count++;
            if(heap[i*2+1]>heap[i]) swap(heap[i*2+1], heap[i]), count++;
        }
        if(count==0) break;
    }
}

void insert(int *heap, int *heapsize, int data)
{

    heap[*heapsize] = data;
    heapify(heap, *heapsize);
    (*heapsize)++;
}

void print(int * heap, int * heapsize)
{
    for(int i = 1; i<*heapsize; i++){
        printf("Childrens of %d:\n", heap[i]);
        if(i*2<*heapsize) printf("%d ", heap[i*2]);
        if(i*2+1<*heapsize) printf("%d\n", heap[i*2+1]);
    }
}


int main()
{
    int heap[100], heapsize = 1;
    while(1){
        printf("1: Insert 2:Print\n");
        int n;
        scanf("%d", &n);
        if(n==1){
            printf("DATA: ");
            int x;
            scanf("%d", &x);
            insert(heap, &heapsize, x);
        }
        if(n==2) print(heap, &heapsize);
    }


}
