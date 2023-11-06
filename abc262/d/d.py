import io
import sys

_INPUT = """\
3
2 6 2

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------
N = int(input())
A = tuple(map(lambda x: int(x) - 1, input().split()))

ans = 0
for bit in range(1 << N):
    amount = 0
    count = 0
    for i in range(N):
        if bit & 1 << i:
            print("A[{}]={}".format(i, A[i]))
            amount += A[i]
            count += 1
    if count == 0:
        continue

    print("amount / count = {}".format(amount / count))
    if amount % count == 0:
        ans += 1

print(ans % 998244353)
