import sys

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for case in range(1, t + 1):
    [n] = [int(x) for x in input().split()]
    activities_start_finish_i =  [[int(x) for x in input().split()]+[j] for j in range(n)]
    activities_start_finish_i.sort(key=lambda x: x[0])

    agenda = ['E']*n
    curr_cameron_t = 0
    curr_james_t = 0
    for i in range(0,n):
        if(int(activities_start_finish_i[i][0]) >= curr_cameron_t):
            # assign the activity to Cameron
            curr_cameron_t = activities_start_finish_i[i][1]
            agenda[activities_start_finish_i[i][2]] = "C"
        elif(int(activities_start_finish_i[i][0]) >= curr_james_t):
            # assign the activity to James
            curr_james_t = activities_start_finish_i[i][1]
            agenda[activities_start_finish_i[i][2]] = "J"
        else:
            agenda = "IMPOSSIBLE"
            break;
    if(agenda != "IMPOSSIBLE"):
        agenda = "".join(agenda)

    print("Case #{}: {}".format(case, str(agenda)))
    # check out .format's specification for more formatting options
