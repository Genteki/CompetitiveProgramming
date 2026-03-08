# c.py
def solve_one(n: int, k: int) -> int:
    """
    Returns the sum of all observed middle-star indices in [1..n], 
    given laziness k.
    """
    # We'll write a local recursive function that returns (cnt, sum).
    # cnt = how many stars get observed
    # sum = sum of those observed-star indices
    def dfs(x: int) -> tuple[int,int]:
        if x < k:
            return (0, 0)        # no stars observed, sum = 0
        if x % 2 == 0:           # x is even
            c_child, s_child = dfs(x // 2)
            return (2*c_child, 2*s_child + (x//2)*c_child)
        else:                    # x is odd
            c_child, s_child = dfs((x - 1)//2)
            return (1 + 2*c_child,
                    (x + 1)//2 + 2*s_child + ((x + 1)//2)*c_child)
    
    # We only want the sum part:
    return dfs(n)[1]


def solve():
    import sys
    input_data = sys.stdin.read().strip().split()
    t = int(input_data[0])
    idx = 1
    answers = []
    for _ in range(t):
        n = int(input_data[idx]); k = int(input_data[idx+1])
        idx += 2
        answers.append(str(solve_one(n, k)))
    print("\n".join(answers))

solve()