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
print(X)
print(CY)


def calc_amount(i, count):
    print("calamount({}, {})".format(i, count))
    if i == N - 1:
        if count == 0:
            print("return 0")
            return 0
        else:
            amount = X[i]
            if count in CY:
                amount += CY[count]
            print("return {}".format(amount))
            return amount

    return max(calc_amount(i + 1, 0), calc_amount(i + 1, count + 1))


max_amount = calc_amount(0, 0)
print(max_amount)
