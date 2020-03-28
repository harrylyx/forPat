t = int(input())

for _ in range(t):
    n = int(input())
    w = [int(x) for x in input().strip().split()]

    zero_cnt = 0
    one_cnt = 0
    for x in w:
        if x == 0:
            zero_cnt += 1
        if x == 1:
            one_cnt += 1

    if one_cnt == n - 1:
        result = n + 2 - zero_cnt
    else:
        result = n + 1 - zero_cnt

    if result > 1:
        print(result)
    else:
        print(-1)
