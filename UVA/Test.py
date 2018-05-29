import sys
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")
	
	
def main():
	print(((13**14-1)//12)%1000000007)
	while(0):
		x = input()
		if(x=="0"): break
		for i in range(2, 100):
			convert(x, i)
		

main()