import sys

def query(i):
    print(i+1)
    return int(input())

# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Kickstart problems.
[t, B] = [int(x) for x in input().split()]
for case in range(1, t + 1):
    arr = [0]*B
    q_num = 0
    L = 0
    R = B-1
    equals = []
    diff = []
    i = 0
    while i < 150:
        rest = i%10
        if(rest != 0 and rest != 1):
            if(L>R):
                break
            arr[L] = query(L)
            arr[R] = query(R)
            if(len(equals) == 0 and arr[L] == arr[R]):
                equals = [L, R]
            if(len(diff) == 0 and arr[L] != arr[R]):
                diff = [L, R]
            L += 1
            R -= 1
            # advance twice here (2 queries)
            i += 2
        elif (rest == 0):
            if len(equals) > 0:
                if(arr[equals[0]] != query(equals[0])):
                    arr = list(map(lambda el: 0 if el == 1 else 1, arr))
            else:
                query(1) # skip this request
            i += 1
        elif (rest == 1):
            if len(diff) > 0:
                if(arr[diff[0]] != query(diff[0])):
                    arr.reverse()
            else:
                query(1) # skip this request
            i += 1
    print("".join(map(lambda el: str(el),arr)))
    if(str(input()) == "N"):
        exit()