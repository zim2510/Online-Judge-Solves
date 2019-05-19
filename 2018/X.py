import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")


def main():
	arr = []
	arr.append(0)
	arr.append(1)

	for i in range(2,501):
	    n=i
	    arr.append(arr[n-1]+arr[n-2])

	while 1:
	    a=int (input())
	    b=int (input())
	    if a==0 and b==0:
	        break
	    i=0;
	    while arr[i]<=a:
	        i=i+1

	    ans=0
	    while arr[i]<=b:
	        i=i+1
	        ans=ans+1
	    print(ans)

main();