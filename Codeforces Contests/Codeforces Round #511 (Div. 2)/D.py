a,b = input().split()
a = int(a)
b = int(b)

if a <= 2 and b <= 2:
    print(0)

elif a == 2 and b > 2:
 if b & 1:
    print(a*b-2)
 else:
     print(a*b)

elif a > 2 and b == 2:
    if a & 1:
        print(a*b-2)
    else:
        print(a*b)

else:
 if (a*b) & 1:
     print(a*b-1)
 else:
     print(a*b)



