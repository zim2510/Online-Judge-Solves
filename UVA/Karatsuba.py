import sys, math
sys.stdin = open("in.txt", "r")
sys.stdout = open("out.txt", "w")

def karatsuba(num1, num2):
	sznum1 = len(num1);
	sznum2 = len(num2);

	n = max(sznum1, sznum2);
	if(n==1): return str(int(num1)*int(num2));
	if(n%2): n+=1;

	while(sznum1!=n): num1 = "0" + num1; sznum1 += 1;
	while(sznum2!=n): num2 = "0" + num2; sznum2 += 1;

	a = num1[:n//2];
	b = num1[n//2:];
	c = num2[:n//2];
	d = num2[n//2:];


	p = str(int(a) + int(b));
	q = str(int(c) + int(d));

	ac = karatsuba(a, c);
	bd = karatsuba(b, d);
	pq = karatsuba(p, q);
	abcd = str(int(pq) - int(ac) - int(bd));

	for i in range(0, n): ac = ac + '0';
	for i in range(0, n//2): abcd = abcd + '0';
	result = str(int(ac) + int(abcd) + int(bd))
	return result	

def main():

	a = input()
	b = input()
	print(int(karatsuba(a, b)))
	return 0

main()

