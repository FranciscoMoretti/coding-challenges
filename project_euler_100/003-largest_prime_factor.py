#!/bin/python3

import sys
import math

def biggestFactor(number):
    while(number%2 == 0):
        number = number//2
    if(number == 1): #all the factors were 2
        return 2
    i = 3
    while(i <= math.sqrt(number)):
        if(number%i == 0):
            number = number//i
            i = 3 #reset the number to try
        else:
            i += 2
    if(number == 1):
        return i
    else:
        return number


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(biggestFactor(n))
