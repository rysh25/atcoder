import io
import sys

_INPUT = """\
2024

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------
Y = int(input())

while Y % 4 != 2:
    Y += 1

print(Y)
