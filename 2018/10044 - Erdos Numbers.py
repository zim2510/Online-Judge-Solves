import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")

def main():
	tc = int(input())
	for i in range(tc):
		S = input().split();
		n, m = int(S[0]), int(S[1])
		for i in range(n):
			K = input().split("., ")
			print(len(K))
			for i in len(K):
				print(K[i])
main()