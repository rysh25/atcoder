import io
import sys

_INPUT = """\
4
-WWW
L-DD
LD-W
LDW-
"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------


N = int(input())
A = [input() for _ in range(N)]
# print(A, file=sys.stderr)

for i in range(N):
    for j in range(N):
        if i == j:
            continue
        # print(
        #     "A[{}][{}]={}, A[{}][{}]={}".format(i + 1, j + 1, A[i][j], j + 1, i + 1, A[j][i]),
        #     file=sys.stderr,
        # )
        if (
            (A[i][j] == "W" and A[j][i] != "L")
            or (A[i][j] == "L" and A[j][i] != "W")
            or (A[i][j] == "D" and A[j][i] != "D")
        ):
            print("incorrect")
            exit()

print("correct")
