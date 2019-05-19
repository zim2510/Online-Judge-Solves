#include <stdio.h>
#include <malloc.h>


struct queue
{
	int MX;
	int *q;
	int sz = 0;
	int frnt = 0;

	queue(int size)
	{
		q = (int*) malloc(size*sizeof(int));
		MX = size;
	}

	int size(){
		return sz;
	}

	int push(int data){
		if(sz<MX){
			q[(frnt+sz)%MX] = data;
			sz++;
			return 1;
		}
		return 0;
	}

	int front()
	{
		if(sz) return q[frnt];
		else return -1;
	}

	int pop()
	{
		if(sz>0){
			frnt++;
			frnt %= MX;
			sz--;
			return 1;
		}

		return 0;
	}
};

int main()
{
	freopen("out.txt", "w", stdout);
	queue x(2);
	x.push(5);
	x.push(4);
	x.push(8);
	printf("%d\n", x.front());
	x.pop();
	printf("%d\n", x.front());
	x.pop();
	x.pop();
	x.push(23);
	x.push(39);
	x.push(44);
	x.push(23);
	x.push(45);
	printf("%d\n", x.front());
	x.pop();
	printf("%d\n", x.front());
	x.pop();
	printf(" %d\n", x.front());
	x.pop();
	x.pop();
	x.pop();
	printf("%d\n", x.front());
	x.push(2);
	printf("%d\n", x.front());
	x.pop();
	x.push(5);
	printf("%d\n", x.front());
	x.push(1);
	printf("%d\n", x.front());
	x.pop();
	printf("%d\n", x.front());
	x.push(0);
	
}