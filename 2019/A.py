import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")

def main():
	x = input().split()
	g = int(x[0])
	l = int(x[1])

	if l%g!=0:
		print("0")
		return 0
		

	seed = l//g;

	cnt = 0

	i = 2

	while i*i<=seed:
		if(seed%i==0):
			cnt += 1;
			while(seed%i==0):
				seed = seed // i;
		i+=1

	if seed>1:
		seed = 1
		cnt+=1

	ans = 1

	for i in range(cnt-1):
		ans *= 2

	print(ans)

main()

