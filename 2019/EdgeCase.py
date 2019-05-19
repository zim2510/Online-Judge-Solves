import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")


def main():
	fib = [4, 7];
	for i in range(2, 100005):
		fib.append(fib[i-1] + fib[i-2])
	
	while(True):
		try:
			x = int(input())
			print(fib[x-3])

		except:
			break
main()