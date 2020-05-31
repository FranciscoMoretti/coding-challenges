#!/bin/python3

import sys
import math

def count5and3multiples(number):
    highestFor3 = (number-1)//3
    highestFor5 = (number-1)//5
    highestFor15 = (number-1)//15

    # Use operator // to do division in integer domain and avoid floating error
    # specially for big numbers
    sumOfMultiples = \
        3 * highestFor3*(highestFor3+1)//2 + \
        5 * highestFor5*(highestFor5+1)//2 - \
        15 * highestFor15*(highestFor15+1)//2 

    return round(sumOfMultiples)

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print (count5and3multiples(n))


