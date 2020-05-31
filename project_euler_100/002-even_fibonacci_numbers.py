#!/bin/python3

import sys

def sumEvenFibbonacciUpTo(count, prev, curr, end):
    newCurr = prev + curr
    if(newCurr < end):
        if(newCurr % 2 == 0):
            count += newCurr
        return sumEvenFibbonacciUpTo(count, curr, newCurr, end)
    else:
        return count

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(sumEvenFibbonacciUpTo(0, 0, 1, n))
