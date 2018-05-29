import sys
sys.stdin = open("in.txt", "r")
tc = int(input())
for i in range(tc):
    n = int(input())
    if(n<=0):
        print("0")
        continue
    result = 0;
    starter = 1;
    while(starter!=n):
        s = n//starter;
        e = n//(starter+1);
        result += (s-e)*(starter);
        tmp = n//(starter+1);
        starter = n//tmp;
    print(result+n);