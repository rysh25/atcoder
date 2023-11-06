import io
import sys

_INPUT = """\
6 3
2 7 1 8 2 8
2 10
3 1
5 5

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------


N, M = map(int, input().split())
X = list(map(int, input().split()))
# CY = [list(map(int, input().split())) for _ in range(M)]
CY = dict(map(int, input().split()) for x in range(M))

# print(N, M)
# print(X)
# print(CY)

dp = [[0] * (N + 1) for i in range(N + 1)]
# print(dp)
for i in range(1, N + 1):
    for j in range(i + 1):
        if j == 0:
            dp[i][j] = max(dp[i - 1])
        else:
            amount = X[i - 1]
            if j in CY:
                amount += CY[j]
            dp[i][j] = dp[i - 1][j - 1] + amount

print(dp)
print(max(dp[N]))
