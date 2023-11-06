import io
import sys

_INPUT = """\
9 12
1 1
2 2
3 3
1 4
2 5
3 6
1 7
2 8
3 9

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------


N, C = map(int, input().split())
TA = [list(map(int, input().split())) for _ in range(N)]

print(N, C)
print(TA)

X = C
print("{}={}".format(X, bin(X)))
for i in range(N):
    for j in range(i + 1):
        if TA[j][0] == 1:
            X = X & TA[j][1]
        elif TA[j][0] == 2:
            X = X | TA[j][1]
        elif TA[j][0] == 3:
            X = X ^ TA[j][1]
    print(X)
