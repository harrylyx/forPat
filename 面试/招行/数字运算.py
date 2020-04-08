def cal(now, last, target):
    global N
    if int(now) + int(last) == target:
        N += 1
        print(now, last)
    if int(now) - int(last) == target:
        N += 1
        print(now, last)
    if len(last) == 1:
        return
    now = str(int(now) + int(last[0]))
    cal(now, last[1:], target)
    now = str(int(now) - int(last[0]))
    cal(now, last[1:], target)
    for i in range(len(last)):
        now = now + last[0:i]
        cal(now, last[i:], target)


def main():
    t = int(input())
    while t:
        s_input = input().strip().split()
        global N
        N = 0
        if len(s_input[0]) != 1:
            cal(s_input[0][0], s_input[0][1:], int(s_input[1]))
        print(N)
        t -= 1


if __name__ == "__main__":
    global N
    main()
