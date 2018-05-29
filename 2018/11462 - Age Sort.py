while True:
	x = int(input())
	if(x==0): break
	nums = input().split();
	for i in range(0, x):
		nums[i] = int(nums[i])
	nums.sort()
	print(*nums)
