#!/bin/python3

# all 6 digit palindromes are multiples of 11
# given palindrome abccba
# =100000a+10000b+1000c+100c+10b+a
# =100001a+10010b+1100c
# =11(9091a+910b+100c)


import sys

def three_digit_factors_of_number(x):
    factors = []
    for i in range(100, 1000):
        if x % i == 0:
            factors.append(i)
    return(factors)

def isPalindrome(pal_candidate):
    pal_s = str(pal_candidate)
    if(pal_s == pal_s[::-1]):
        return True
    else:
        return False

def largestPalindromeProductLowerThan(number):
    pal_candidate = ((number-1)//11)*11 #all palindromes like this are multiples of 11
    while(pal_candidate > 100000):
        if(isPalindrome(pal_candidate)):
            palindrome = pal_candidate
            factors = three_digit_factors_of_number(palindrome)
            for j in range(0,len(factors)):
                if palindrome//factors[j] >= 100 and palindrome//factors[j] < 1000:
                    return palindrome
        pal_candidate -= 11
    return("not found")


t = int(input().strip())
for a0 in range(t):
    n = int(input().strip())
    print(largestPalindromeProductLowerThan(n))