import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")

def main():
	fib=[1, 1]
	for i in range(2, 4005):
		fib.append(fib[i-1]+fib[i-2])
	while(True):
		x = int(input())
		if(x==0): break
		print(fib[x*2-1])
main()