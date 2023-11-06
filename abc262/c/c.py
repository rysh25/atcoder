import io
import sys

_INPUT = """\
10
5 8 2 2 1 6 7 2 9 10

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------
N = int(input())
a = tuple(map(lambda x: int(x) - 1, input().split()))

count = 0
for i in range(N - 1):
    if a[i] == i:
        for j in range(i + 1, N):
            if a[j] == j:
                # print("a ({}, {})".format(i + 1, j + 1))
                count += 1
    else:
        # i = 2
        if i < a[i] and a[a[a[i]]] == a[i] and a[a[i]] == i:
            # print("({}, {})".format(i + 1, a[i] + 1))w
            count += 1

print(count)
