def f(a, b):
    g = max(a, b)
    t =  g * (g - 1) + 1 + ((b - a) * (g % 2 or -1))
    return t

for i in range(int(input())):
    a, b = [int(n) for n in input().split(' ')]
    print(f(a, b))