# c.py
import sys
import threading
def main():
    import sys
    import math
    import threading

    sys.setrecursionlimit(1 << 25)

    t = int(sys.stdin.readline())
    # Precompute valid partitions
    from itertools import combinations

    adj = [
        [1,3],      # 0
        [0,2,4],    # 1
        [1,5],      # 2
        [0,4],      # 3
        [1,3,5],    # 4
        [2,4],      # 5
    ]

    valid_partitions = []

    cells = [0,1,2,3,4,5]
    combs = list(combinations(cells, 3))
    for comb in combs:
        group1 = set(comb)
        group2 = set(cells) - group1
        # Check if group1 is connected
        visited1 = set()
        stack = [next(iter(group1))]
        while stack:
            node = stack.pop()
            if node in visited1:
                continue
            visited1.add(node)
            for neighbor in adj[node]:
                if neighbor in group1 and neighbor not in visited1:
                    stack.append(neighbor)
        if len(visited1) != 3:
            continue
        # Check if group2 is connected
        visited2 = set()
        stack = [next(iter(group2))]
        while stack:
            node = stack.pop()
            if node in visited2:
                continue
            visited2.add(node)
            for neighbor in adj[node]:
                if neighbor in group2 and neighbor not in visited2:
                    stack.append(neighbor)
        if len(visited2) != 3:
            continue
        # Store partition
        partition = [0]*6
        for cell in group1:
            partition[cell] = 1
        for cell in group2:
            partition[cell] = 2
        valid_partitions.append(partition)

    for _ in range(t):
        n = int(sys.stdin.readline())
        s1 = sys.stdin.readline().strip()
        s2 = sys.stdin.readline().strip()
        total_districts_won = 0
        for block_start in range(0, n, 3):
            block_cells = []
            # Cells are numbered from 0 to 5
            # Map cells to their 'A' or 'J' value
            cell_values = []
            cell_positions = []
            for row in range(2):
                for col in range(block_start, block_start+3):
                    if row == 0:
                        cell_values.append(s1[col])
                    else:
                        cell_values.append(s2[col])
                    cell_positions.append((row, col))
            max_wins = -1
            for partition in valid_partitions:
                wins = 0
                for district_num in [1,2]:
                    district_cells = [i for i in range(6) if partition[i]==district_num]
                    A_count = sum(1 for i in district_cells if cell_values[i]=='A')
                    if A_count >=2:
                        wins +=1
                if wins > max_wins:
                    max_wins = wins
            total_districts_won += max_wins
        print(total_districts_won)
threading.Thread(target=main).start()