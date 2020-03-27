n = input()
n = int(n)

def fexp(n):
    ans = int(1)
    b = int(10)
    e = int(n)
    while e > 0:
        if e & 1: ans = ans*b
        b = b*b
        e = e//2;
    return ans

cnt = 0

while n > 0:
    aux = str(n)
    op2 = fexp(len(aux))
    op1 = fexp(len(aux)-1)
    if n - op1 < op2 - n:
        n = n - op1
    else :
        n = op2 - n
    cnt = cnt + 1

print(cnt)
