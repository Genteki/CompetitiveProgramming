n = int(input())
a = list(map(int, input().split()))
q = int(input())
queries = [tuple(map(int, input().split())) + (i,) for i in range(q)]

prefix_sums = [0] * (n + 1)
prefix_sums_cum = [0] * (n + 1)
for i in range(1, n + 1):
    prefix_sums[i] = prefix_sums[i - 1] + a[i - 1]
    prefix_sums_cum[i] = prefix_sums_cum[i - 1] + prefix_sums[i]

cnt_l = [0] * (n + 1)
pos_l = [0] * (n + 1)
cum_cnt = [0] * (n + 1)
cum_sum = [0] * (n + 1)

pos_l[1] = 1
for l in range(1, n + 1):
    cnt_l[l] = n - l + 1
    if l > 1:
        pos_l[l] = pos_l[l - 1] + cnt_l[l - 1]
    cum_cnt[l] = cum_cnt[l - 1] + cnt_l[l]

sum_l = [0] * (n + 1)
for l in range(1, n + 1):
    cnt = cnt_l[l]
    total = (prefix_sums_cum[n] - prefix_sums_cum[l - 1]) - cnt * prefix_sums[l - 1]
    sum_l[l] = total
    cum_sum[l] = cum_sum[l - 1] + sum_l[l]

def find_block(pos):
    l = 1
    r = n
    while l <= r:
        m = (l + r) // 2
        if pos_l[m] <= pos <= pos_l[m] + cnt_l[m] - 1:
            return m
        elif pos < pos_l[m]:
            r = m - 1
        else:
            l = m + 1
    return -1

answers = [0] * q
for l_i, r_i, idx in queries:
    l1 = 1
    r1 = n
    while l1 <= r1:
        m = (l1 + r1) // 2
        if pos_l[m] <= l_i <= pos_l[m] + cnt_l[m] - 1:
            block_l = m
            break
        elif l_i < pos_l[m]:
            r1 = m - 1
        else:
            l1 = m + 1

    l2 = 1
    r2 = n
    while l2 <= r2:
        m = (l2 + r2) // 2
        if pos_l[m] <= r_i <= pos_l[m] + cnt_l[m] - 1:
            block_r = m
            break
        elif r_i < pos_l[m]:
            r2 = m - 1
        else:
            l2 = m + 1

    result = 0

    if block_l == block_r:
        # Same block
        p1 = l_i - pos_l[block_l]
        p2 = r_i - pos_l[block_l]
        a = block_l + p1
        b = block_l + p2
        total = (prefix_sums_cum[b] - prefix_sums_cum[a - 1]) - (b - a + 1) * prefix_sums[block_l - 1]
        result = total
    else:
        # Partial block at block_l
        p1 = l_i - pos_l[block_l]
        p2 = cnt_l[block_l] - 1
        a = block_l + p1
        b = block_l + p2
        total = (prefix_sums_cum[b] - prefix_sums_cum[a - 1]) - (b - a + 1) * prefix_sums[block_l - 1]
        result += total

        # Full blocks between block_l and block_r
        if block_r - block_l > 1:
            result += cum_sum[block_r - 1] - cum_sum[block_l]

        # Partial block at block_r
        p1 = 0
        p2 = r_i - pos_l[block_r]
        a = block_r + p1
        b = block_r + p2
        total = (prefix_sums_cum[b] - prefix_sums_cum[a - 1]) - (b - a + 1) * prefix_sums[block_r - 1]
        result += total

    answers[idx] = result

for ans in answers:
    print(ans)