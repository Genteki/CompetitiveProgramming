# e.py

MOD = 998244353

import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    max_a = max(a)
    freq = [0]*(max_a+2)
    for num in a:
        freq[num] +=1
    c0 = freq[0]
    if c0 == 0:
        print(0)
        continue
    total_subseq = pow(2, n, MOD) - 1
    ans = 0
    # Calculate number of subsequences containing at least one zero
    subseq_with_zero = (pow(2, c0, MOD) - 1) * pow(2, n - c0, MOD) % MOD
    # For MEX values from 1 to max_a+1
    prefix = [0]*(max_a+2)
    for i in range(1, max_a+2):
        prefix[i] = prefix[i-1] + (freq[i-1]>0)
    for mex in range(1, max_a+2):
        if freq[mex-1]==0:
            break
        ways = pow(2, freq[mex-1]-1, MOD)
        ans = (ans + ways)%MOD
    ans = (ans * pow(2, n - c0, MOD))%MOD
    print(ans)