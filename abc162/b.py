import io
import sys

_INPUT = """\
1000000

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

N = int(input())

count = 0
for i in range(N + 1):
    if i % 3 != 0 and i % 5 != 0:
        count += i
print(count)
