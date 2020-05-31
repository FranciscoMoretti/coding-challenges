#!/bin/python3

import sys

# Python program to check if 
# given number is prime or not 

num = 11

def isPrime(num):
    # If given number is greater than 1 
    if num > 1 and num != 4:     
        # Iterate from 2 to n / 2 
        for i in range(2, num//2): 
            # If num is divisible by any number between 
            # 2 and n / 2, it is not prime 
            if (num % i) == 0: 
                return False 
                break
        else: 
            return True
    else: 
        return False

def primesUpTo(num):
    primes = []
    for i in range(num+1):
        if isPrime(i):
            primes.append(i)
    return primes

def primePowersCloserTo(num):
    primes = primesUpTo(num)
    primePowers = []
    for prime in primes:
        power = 1
        while(pow(prime,power+1) <= num):
            power += 1
        primePowers.append(pow(prime,power))
    return primePowers

def smallestMultiple(num):
    primePowers = primePowersCloserTo(num)
    n = 1
    for i in primePowers:
        n = i*n
    return n

t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    smallest = smallestMultiple(n)
    print(smallest)
