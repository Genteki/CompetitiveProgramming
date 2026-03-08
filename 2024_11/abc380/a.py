a = list(input())
l = [0] * 10
for c in a:
    if(c == '1'):
        l[1] += 1
    elif (c == '2'):
        l[2] += 1
    elif (c == '3'):
        l[3] += 1

if (l[1] == 1 and l[2] == 2 and l[3] == 3):
    print("Yes")
else:
    print("No")