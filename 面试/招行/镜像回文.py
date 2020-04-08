mm = {1: 1, 2: 5, 5: 2, 3: 8, 8: 3, 4: 7, 7: 4, 6: 9, 9: 6}


def main():
    t = int(input())
    while t:
        s = input()
        left = 0
        right = len(s) - 1
        flag = 1
        while left < right:
            if mm[int(s[left])] != int(s[right]):
                print("NO")
                flag = 0
                break
            left += 1
            right -= 1
        if len(s) == 0 or len(s) == 1:
            print("NO")
        elif left == right:
            print("NO")
        elif flag == 1:
            print("YES")
        t -= 1


if __name__ == "__main__":
    main()
