import sys

def invertPath(path):
    new = str()
    for dir in path:
        if(dir == 'S'):
            new += str('E')
        else:
            new += str('S')
    return new
 
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
    n = int(input().strip())
    lydia_path = str(input().strip())
    my_path = invertPath(lydia_path)
    print("Case #{}: {}".format(i, my_path))
    # check out .format's specification for more formatting options
