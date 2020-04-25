import sys

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for case in range(1, t + 1):
    s = str(input())
    index = 0
    curr_depth = 0
    result = str()
    while(index < len(s)):
        digit = int(s[index])
        diff = digit - curr_depth
        if(diff > 0):
            for i in range(0, diff):
                result += "("
        elif(diff < 0):
            for i in range(0, -diff):
                result += ")"
        result += str(s[index])
        curr_depth = digit

        index += 1
    for i in range(0, curr_depth):
                result += ")"
    
    print("Case #{}: {}".format(case, result))
    # check out .format's specification for more formatting options
