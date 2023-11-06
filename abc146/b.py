import io
import sys

_INPUT = """\
0 100

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

A, B = map(int, input().split())

if 13 <= A:
    print(B)
elif 6 <= A <= 12:
    # 小数点以下は切り捨て
    print(B // 2)
else:
    print(0)
