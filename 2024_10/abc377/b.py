# b.py

m = []
for _ in range(8):
    s = input()
    m.append(s)

n = [list(row) for row in m]  # Convert each row (string) into a list of characters

for i in range(8):
    for j in range(8):
        if (m[i][j] == '#'):
            for k in range(8):
                n[i][k] = '#'
                n[k][j] = '#'

ans = 0
for i in range(8):
    for j in range(8):
        if (n[i][j] == '.'):
            ans += 1
print(ans)