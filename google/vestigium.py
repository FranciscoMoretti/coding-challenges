import sys

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for case in range(1, t + 1):
    [n] = [int(x) for x in input().split()]
    matrix =  [[int(x) for x in input().split()] for j in range(n)]
    trace = sum([matrix[i][i] for i in range(n)])
    rows = [[ 0 for i in range(n)] for j in range(n)]
    columns = [[ 0 for i in range(n)] for j in range(n)]
    for i in range(0, n): # For stacks 1 to n
        for j in range(0, n): # And for pick amount 0 to p -> j
            rows[i][matrix[i][j]-1] += 1
            columns[j][matrix[i][j]-1] += 1
    n_row = len(list(filter(lambda x: (max(x)>1), rows)))
    n_col = len(list(filter(lambda x: (max(x)>1), columns)))

    print("Case #{}: {} {} {} ".format(case, trace, n_row, n_col))
    # check out .format's specification for more formatting options
