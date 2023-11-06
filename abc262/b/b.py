import io
import sys

_INPUT = """\
7 10
1 7
5 7
2 5
3 6
4 7
1 5
2 4
1 3
1 6
2 7

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

N, M = map(int, input().split())
# UV = [tuple(map(lambda x: int(x), input().split())) for _ in range(M)]

edges = [[False] * N for _ in range(N)]

for _ in range(M):
    U, V = map(int, input().split())
    edges[U - 1][V - 1] = True
    edges[V - 1][U - 1] = True

count = 0
for a in range(N):
    for b in range(a + 1, N):
        for c in range(b + 1, N):
            if edges[a][b] and edges[b][c] and edges[c][a]:
                count += 1

print(count)
