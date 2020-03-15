t = input()
t = int(t)

prod = []
p = []
st = set()
mp = {}

def gcd(a, b):
    if b == 0: return int(a)
    else: return gcd(b, a%b)

for i in range(t):
    n, m = input().split()
    n = int(n)
    m = int(m)

    prod.clear()
    p.clear()
    st.clear()
    mp.clear()
    for j in range(m+1): p.append(0)

    prod = input().split()
    for k in range(m): prod[k] = int(prod[k])

    for j in range(m - 1):
        pax = gcd(prod[j], prod[j+1])
        if pax != prod[j]:
            p[j] = prod[j]//pax
            index = j
            break

    for k in range(index, m): p[k+1] = prod[k]//p[k]
    for k in range(index, 0, -1) : p[k-1] = prod[k-1]//p[k] 
    for k in range(m+1): st.add(p[k])
    
    idx = 0
    for x in sorted(st):
        mp[x] = chr(ord('A') + idx)
        idx = idx + 1

    print("Case #" + str(i+1) + ": ", end='')
    for j in range(m+1): print(mp[int(p[j])], end='')
    print()
