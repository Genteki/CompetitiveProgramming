MOD = 998244353
MAX_N = 10 ** 3 + 5

# Precompute factorials and inverse factorials
factorial = [1] * MAX_N
inv_factorial = [1] * MAX_N

for i in range(1, MAX_N):
    factorial[i] = factorial[i - 1] * i % MOD

# Fermat's little theorem for inverse modulo
inv_factorial[MAX_N - 1] = pow(factorial[MAX_N - 1], MOD - 2, MOD)
for i in range(MAX_N - 2, -1, -1):
    inv_factorial[i] = inv_factorial[i + 1] * (i + 1) % MOD

# Function to compute combinations modulo MOD
def comb(n, k):
    if k < 0 or k > n:
        return 0
    return factorial[n] * inv_factorial[k] % MOD * inv_factorial[n - k] % MOD

# Precompute Bell numbers up to MAX_N
bell_numbers = [0] * MAX_N
bell_numbers[0] = 1

for n in range(1, MAX_N):
    bell = 0
    for k in range(n):
        bell += comb(n - 1, k) * bell_numbers[k] % MOD
        bell %= MOD
    bell_numbers[n] = bell

t = int(input())
for _ in range(t):
    n = int(input())
    print(bell_numbers[n - 1])