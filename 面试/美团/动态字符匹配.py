import re


def main():
    n, k = input().strip().split()
    raw_dict = {}
    for i in range(int(k)):
        raw_dict[i+1] = input()
    n = int(n)
    now_dict = raw_dict.copy()
    while n:
        command = input()
        c = command[0]
        command = command[1:]
        if c == "?":
            ans = 0
            for x in now_dict:
                ans += len(re.findall(now_dict[x], command))
            print(ans)
        elif c == "+":
            if int(command) not in now_dict:
                now_dict[int(command)] = raw_dict[int(command)]
        elif c == "-":
            if int(command) in now_dict:
                now_dict.pop(int(command))
        n -= 1


if __name__ == "__main__":
    main()
