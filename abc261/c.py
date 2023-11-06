import io
import sys

_INPUT = """\
11
a
a
a
a
a
a
a
a
a
a
a

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------


N = int(input())
S = [input() for _ in range(N)]
print(S)

dup = {}
for i in range(N):
    if S[i] in dup:
        dup[S[i]] += 1
        print("{}({})".format(S[i], dup[S[i]]))
    else:
        dup[S[i]] = 0
        print(S[i])
