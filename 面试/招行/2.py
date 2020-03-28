# a = [4, 9, 5, 2, 2]
# b = [1, 3, 5, 1, 4]

# a = [2, 1, 2]
# b = [2, 1, 2]


def cal(a, b):
    return all(((b[1] - a[1]) >= 0, (b[0] - a[0]) >= 0))


t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(x) for x in input().strip().split()]
    b = [int(x) for x in input().strip().split()]

    if n <= 1:
        print(0)
    else:
        c = sorted(zip(a, b), key=lambda x: (x[0], x[1]), reverse=True)

        cnt = 0
        for i in range(len(c) - 1):
            if not cal(c[i + 1], c[i]):
                cnt += 1
        print(cnt if cnt > 0 else 1)
