# b.py
n = int(input())
q = []
r = []
for _ in range(n):
    qi, ri = map(int, input().split())
    q.append(qi)
    r.append(ri)

Q = int(input())
for _ in range(Q):
    i, d = map(int, input().split())
    i -= 1;
    x = (d - r[i])
    if ( x <= 0 ):
        print(r[i])
    else:
        x = (x + q[i] - 1) // q[i]
        x = q[i] * x + r[i]
        print(x)