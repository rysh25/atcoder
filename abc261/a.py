import io
import sys

_INPUT = """\
0 3 3 7

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

L1, R1, L2, R2 = map(int, input().split())

ans = 0
if L1 <= L2 <= R2 <= R1:
    ans = R2 - L2
elif L2 <= L1 <= R1 <= R2:
    ans = R1 - L1
elif L1 <= L2 <= R1 <= R2:
    ans = R1 - L2
elif L2 <= L1 <= R2 <= R1:
    ans = R2 - L1
else:
    ans = 0

print(ans)
