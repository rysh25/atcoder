import io
import sys

_INPUT = """\
11
1 9
1 9
1 8
1 2
1 4
1 4
1 3
1 5
1 3
2
3

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

from collections import deque

MOD = 998244353

Q = int(input())

S = deque()
S.append(1)

ans = 1
for i in range(Q):
    q = list(map(int, input().split()))
    if q[0] == 1:
        ans = (ans * 10 + q[1]) % MOD
        S.append(q[1])
    elif q[0] == 2:
        r = S.popleft()
        ans = (ans - (pow(10, len(S), MOD) * r)) % MOD
    else:
        print(ans % MOD)
