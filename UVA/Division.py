import sys, math
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")

while True:
	try:
		nums = []
		S = input().split()
		for i in S: nums.append(int(i))
		x = (nums[0]**nums[1]-1)
		y = (nums[0]**nums[2]-1)
		res = x//y
		print("(",nums[0],"^"+str(nums[1])+"-1)/("+str(nums[0])+"^"+str(nums[2])+"-1) ", end="", sep="")
		if(x%y==0 and math.log10(res)<=100): print(int(res))
		else: print("is not an integer with less than 100 digits.")
	except:
		break;