N, A, B = map(int, input().split())

ans = 0
for i in range(1, N + 1):
    # print("i:", i)
    sum = 0
    for c in str(i):
        # print("c:", c)
        sum += int(c)

    if A <= sum <= B:
        # print(f"i: {i}, sum: {sum}")
        ans += i

print(ans)
