import sys
sys.stdin = open("in.txt", "r")
while(True):
	a = input();
	a = a.split();
	x = int(a[0])
	y = int(a[1])
	if(x==0 and y==0): break
	print(x**y)