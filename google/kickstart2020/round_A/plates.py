import sys

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
t = int(input())  # read a line with a single integer
for case in range(1, t + 1):
    [n, k, p] = [int(x) for x in input().split()]
    plates_stacks =  [[int(x) for x in input().split()] for j in range(n)]
    sums = [[sum(plates_stacks[j][0:i]) for i in range(k+1)] for j in range(n)]
    dp = [[ 0 for i in range(p+1)] for j in range(n)]
    dp[0][0:k+1] = sums[0][0:k+1]
    for i in range(1, n): # For stacks 1 to n
        for j in range(1, p+1): # And for pick amount 0 to p -> j
            for x in range(0, min(j, k)+1): # x plates selected of the row i combined with prev maximums
                dp[i][j] = max(dp[i][j], sums[i][x]+dp[i-1][j-x])
    print("Case #{}: {}".format(case, dp[n-1][p]))
    # check out .format's specification for more formatting options
