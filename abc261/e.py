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


n, c = map(int, input().split())
ta = [list(map(int, input().split())) for _ in range(n)]

# print(n, c)
# print(ta)

ans = [0] * n
# print(ans)

for k in range(30):
    func = [0, 0]
    crr = c >> k & 1
    for i in range(n):
        f = [0, 0]
        print("{}, {}".format(c, ta[i][1]))
        x = c >> ta[i][1] & 1
        if ta[i][0] == 1:
            f[0], f[1] = (0 & x, 1 & x)
        if ta[i][0] == 2:
            f[0], f[1] = (0 | x, 1 | x)
        if ta[i][0] == 3:
            f[0], f[1] = (0 ^ x, 1 ^ x)
        func[0], func[1] = (f[func[0]], f[func[1]])
        crr = func[crr]
        ans[i] |= crr << k

x = c
# print("{}={}".format(x, bin(x)))

print(ans)
