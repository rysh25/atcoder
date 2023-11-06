import io
import sys

_INPUT = """\
13
ABCDEFGHIJKLMNOPQRSTUVWXYZ

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------

N = int(input())
S = input()

ans = ""
for c in S:
    ans += chr(((ord(c) + N) + ord("A")) % 26 + ord("A"))

print(ans)
