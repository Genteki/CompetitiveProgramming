(r, g, b) = map(int, input.split())
c = input()
if c == 'Red':
    print(max(g,b))
elif c == 'Blue':
    print(max(r, g))
else:
    print(max(r, b))