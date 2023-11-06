import io
import sys

_INPUT = """\
1 1

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

A, B = map(int, input().split())

if B % A == 0:
    print(A + B)
else:
    print(B - A)
