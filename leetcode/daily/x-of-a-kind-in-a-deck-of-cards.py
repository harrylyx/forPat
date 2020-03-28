import collections
from functools import reduce


def gcd(num1, num2):
    while num1 != num2:
        if num1 > num2:
            num1 -= num2
        else:
            num2 -= num1
    return num1


def hasGroupsSizeXMine(deck) -> bool:
    r_set = set(collections.Counter(deck).values())
    if 1 in r_set:
        return False
    gcd_list = gcd(min(r_set))
    # gcd_list.append(min(r_set))
    gcd_list = set(gcd_list)
    print(gcd_list)

    for i in r_set:
        for j in gcd_list:
            temp_set = set()
            if i % j != 0:
                temp_set.add(j)
        gcd_list -= temp_set
        if len(gcd_list) == 0:
            return False
    return True


def hasGroupsSizeX(deck) -> bool:
    r_set = collections.Counter(deck).values()
    return reduce(gcd, r_set) >= 2


if __name__ == "__main__":
    print(hasGroupsSizeX([1, 1, 1, 1, 1, 1, 2, 2, 2,
                          2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3]))
