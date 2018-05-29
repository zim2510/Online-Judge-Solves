import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")

def main():
	fib = [1, 1]
	for i in range(2, 1501):
		fib.append(fib[i-1]+fib[i-2])
	fibsum = [0]
	for i in range(1, 1501):
		fibsum.append(fibsum[i-1]+fib[i])
	tc = 0
	while True:
		tc += 1
		x = int(input())
		if(x==0): break
		print("Set "+str(tc)+":")
		if(x==1): result = 0
		else: result = fibsum[x-2] + fib[x-1]//2 + (fib[x-1]%2)
		print(result)
	print(fib[1500])
main()

