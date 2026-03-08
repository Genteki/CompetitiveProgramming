# d.py
t = int(input())
for _ in range(t):
    n = int(input())
    intervals = []
    for i in range(n):
        l, r = map(int, input().split())
        intervals.append((l, -r, i))  # Store index to map results back
    intervals.sort()
    
    ans = [0] * n
    prev_l, prev_r = None, None
    L_p, R_p = None, None
    count_same = {}
    for i in range(n):
        l, neg_r, idx = intervals[i]
        r = -neg_r
        key = (l, r)
        count_same[key] = count_same.get(key, 0) + 1
        if i > 0:
            prev_l, prev_neg_r, prev_idx = intervals[i-1]
            prev_r = -prev_neg_r
            if prev_l <= l and prev_r >= r:
                # Previous interval covers current interval
                ans[idx] = max(0, min(prev_r, r) - max(prev_l, l) + 1 - max(0, min(r, prev_r) - max(l, prev_l) + 1))
            elif count_same[key] > 1:
                # Multiple users with the same interval
                ans[idx] = 0  # They are predictors of each other
        else:
            ans[idx] = 0  # First user has no predictors
    for a in ans:
        print(a)