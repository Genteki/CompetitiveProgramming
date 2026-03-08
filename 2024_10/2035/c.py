def solve():
    t = int(input())  # number of test cases
    for _ in range(t):
        n = int(input())
        if n % 2 == 1:
            # If n is odd, alternate starting from 2, placing odd numbers first
            p = [i for i in range(2, n + 1, 2)] + [i for i in range(1, n + 1, 2)]
        else:
            # If n is even, alternate placing even numbers first
            p = [i for i in range(1, n + 1, 2)] + [i for i in range(2, n + 1, 2)]
        
        # We assume the generated permutation is near-optimal.
        print(n)
        print(" ".join(map(str, p)))

# Example usage:
solve()