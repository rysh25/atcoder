import io
import sys

_INPUT = """\
6 3
2 7 1 8 2 8
2 10
3 1
5 5

"""

sys.stdin = io.StringIO(_INPUT)

# ----------------------------------------------------------


N, M = map(int, input().split())
X = list(map(int, input().split()))
# CY = [list(map(int, input().split())) for _ in range(M)]
CY = dict(map(int, input().split()) for x in range(M))

# print(N, M)
# print(X)
# print(CY)

max_amount = 0
for bit in range(1 << N):
    count = 0
    amount = 0
    combination = []
    for i in range(N):
        if bit & 1 << i:
            # print('1', end='')
            count += 1
            amount += X[i]
            if count in CY:
                amount += CY[count]
        else:
            # print('0', end='')
            count = 0

    # print()
    max_amount = max(amount, max_amount)
    # print("amount={}".format(amount))

print(max_amount)
