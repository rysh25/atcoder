import io
import sys

_INPUT = """\
13 3

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

A, B = map(int, input().split())

a = A + B
b = A - B
c = A * B

if a >= b and a >= c:
    print(a)
elif b >= a and b >= c:
    print(b)
elif c >= a and c >= b:
    print(c)
