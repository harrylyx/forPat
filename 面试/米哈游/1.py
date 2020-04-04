import re

s = input()
pattern = input()

if re.match(pattern, s):
    print(True)
else:
    print(False)
