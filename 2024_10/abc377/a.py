s = input()

cnt = [0 for _ in range(3)]

for i in range(3):
    if (s[i] == 'A'): 
        cnt[0]+=1
    elif (s[i] == 'B'):
        cnt[1]+=1
    elif (s[i] == 'C'):
        cnt[2]+=1

if (cnt[0] == 1 and cnt[1] == 1 and cnt[2] == 1):
    print("Yes")
else:
    print("No")