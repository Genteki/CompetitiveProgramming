# e.py
def solve():
    t = int(input())  # Number of test cases
    for _ in range(t):
        n, k = map(int, input().split())  # Number of vertices and divisibility factor k
        
        a = list(map(int, input().split()))  # Types of vertices in the first graph
        m1 = int(input())  # Number of edges in the first graph
        for _ in range(m1):
            input()  # Ignore the edges (as they are not needed for the solution)
        
        b = list(map(int, input().split()))  # Types of vertices in the second graph
        m2 = int(input())  # Number of edges in the second graph
        for _ in range(m2):
            input()  # Ignore the edges (as they are not needed for the solution)
        
        # Count outgoing (1) and incoming (0) vertices in both graphs
        out_first = sum(a)  # Number of outgoing vertices in the first graph
        in_first = n - out_first  # Number of incoming vertices in the first graph
        
        out_second = sum(b)  # Number of outgoing vertices in the second graph
        in_second = n - out_second  # Number of incoming vertices in the second graph
        
        # Check if it's possible to draw the required edges
        if out_first == in_second and in_first == out_second:
            print("YES")
        else:
            print("NO")

# Reading input and calling the function
solve()