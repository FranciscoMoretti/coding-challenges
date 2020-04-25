import sys

def splitFours(number):
    snum = list(str(number))
    B = 0
    for i in range(len(snum)):
        if snum[i] == '4':
            snum[i] = '2'
            B += 2*pow(10, len(snum)-i-1)
    return [int("".join(snum)), B]
 
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    n = int(input().strip())
    [A, B] = splitFours(n)
    print("Case #{}: {} {}".format(i, A, B))
    # check out .format's specification for more formatting options
