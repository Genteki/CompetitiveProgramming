# d.py
import sys
import bisect
import math

def solve():
    t = int(input())  # Number of test cases
    for _ in range(t):
        n, m = map(int, input().split())  # n = length of a, m = length of b
        a = list(map(int, input().split()))  # Array a
        b = list(map(int, input().split()))  # Array b (strictly decreasing)
        
        # Sort a to remove smallest elements first
        a.sort()
        
        total_cost = 0
        possible = True
        i = 0  # Pointer for array a
        
        # Try to remove elements by checking each k (starting from 1, i.e., b[0])
        for k in range(m):
            current_sum = 0
            count = 0
            
            # Try to remove as much as we can from a with current b[k]
            while i < n and current_sum + a[i] <= b[k]:
                current_sum += a[i]
                count += 1
                i += 1
                
            # If we removed something, the cost is m - k (remember k is 0-based)
            if count > 0:
                total_cost += m - k - 1
            
            # If we managed to remove all elements from a, break early
            if i == n:
                break
        
        # If there are still elements left in a, it's impossible
        if i < n:
            print(-1)
        else:
            print(total_cost)

# Example test case
solve()