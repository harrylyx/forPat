import collections

if __name__ == "__main__":
    n = int(input())
    w = [int(x) for x in input().strip().split()]

    all_list = []
    for i in range(n):
        for j in range(i, n):
            temp = []
            for k in range(i, j + 1):
                temp.append(w[k])
            all_list.append(max(temp))

    cnt = len(all_list)
    all_dict = collections.Counter(all_list)
    r = 0
    for k, v in all_dict.items():
        r += k * v / cnt
    print("%.6f" % r)


# 1 2 3 3
# 1 2 3 3 12 23 33 123 233 1233
