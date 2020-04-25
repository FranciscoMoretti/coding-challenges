import sys

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    [n, b] = [int(x) for x in input().split()]
    a = [int(x) for x in input().split()]
    a.sort()
    num_bought = 0
    j = 0
    while(j < len(a)):
        b -= a[j]
        if b >= 0:
            num_bought += 1
            j += 1
        else:
            break
    print("Case #{}: {}".format(i, num_bought))
    # check out .format's specification for more formatting options
