class P:
    def _init_ (self):
        self.a = 0
        self.b = 0

a = []
ans = 0
n = int(input())
kk = input().split(' ')
Sum = int(kk[0])
for i in range(n):
    pos = P()
    res = input().split(' ')
    pos.a, pos.b = int(res[0]), int(res[1])
    a.append(pos)

def cmp(a):
    return a.a * a.b

a.sort(key = cmp)

for p in a :
    ans = max(ans, Sum // p.b)
    Sum *= p.a

print(ans)