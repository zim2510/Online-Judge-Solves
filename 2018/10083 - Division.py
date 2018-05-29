import sys, math

while True:
	try:
		flag = 0
		nums = []
		S = input().split()
		for i in S: nums.append(int(i))

		if(nums[0]==1):
			flag = 0
		elif(nums[1]==nums[2]):
			flag = 1
		elif(nums[1]<nums[2]):
			flag = 0
		elif((nums[1] - nums[2]) * math.log10(nums[0]) > 99):
			flag = 0
		else:
			x = (nums[0]**nums[1]-1)
			y = (nums[0]**nums[2]-1)
			res = x//y
			if(x%y==0 and math.log10(res)<=100): flag = int(res)

		print("(",nums[0],"^"+str(nums[1])+"-1)/("+str(nums[0])+"^"+str(nums[2])+"-1) ", end="", sep="")
		if(flag): print(flag)
		else: print("is not an integer with less than 100 digits.")
	except:
		break;