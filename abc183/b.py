import io
import sys

_INPUT = """\
-9 99 -999 9999
"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------


Sx, Sy, Gx, Gy = list(map(int, input().split()))

# x = Sx + Sy * (Gx - Sx) / (Gy + Sx)
print((Gx - Sx) * (Sy / (Sy + Gy)) + Sx)
