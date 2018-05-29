def main():
	fibs = [1, 2]
	for i in range(2, 101):
		fibs.append(fibs[i-1]+fibs[i-2])

	while True:
		try:
			a = input();
			b = input();
			a = a[::-1]
			b = b[::-1]
			alen = len(a)
			blen = len(b)


			s = 0;
			for i in range(0, alen):
				if(a[i]=='1'):
					s += fibs[i]
			for i in range(0, blen):
				if(b[i]=='1'):
					s += fibs[i]

			i = 100
			start = 0
			out = ""
			while(i>=0):
				if(fibs[i]<=s):
					start = 1
					out = out+"1"
					s -= fibs[i]
				else:
					if(start==1): out = out+"0"
				i-=1

			if(out!=""): print(out)
			else: print("0")
			ignore = input()
			print(ignore)
		except:
			break


main()