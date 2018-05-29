tc = int(input())
for i in range(tc):
	S = input().split()
	for i in range(2):
		S[i] = S[i][::-1]

	R = str(int(S[0]) + int(S[1]))
	print(int(R[::-1]))
