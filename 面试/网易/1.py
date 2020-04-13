from collections import Counter


def main():
    line = input().strip().split(",")
    target = int(line[0])
    A = [int(x) for x in line[1:]]
    c = Counter(A)
    res = 0
    for i, x in c.items():
        for j, y in c.items():
            k = target - i - j
            if k not in c:
                continue
            if i == j == k:
                res += x * (x - 1) * (x - 2) // 6
            elif i == j != k:
                res += x * (x - 1) // 2 * c[k]
            elif i < j and j < k:
                res += x * y * c[k]
    return res % (10**9 + 7)


if __name__ == "__main__":
    print(main())
