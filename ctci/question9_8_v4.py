#!/usr/bin/python

"""
9.8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents)
and pennies (1 cent), write code to calculate the number of ways of representing n
cents
"""

import sys

def getnextstatus(status):
    if (status == 25):
        return 10
    elif (status == 10):
        return 5
    elif (status == 5):
        return 1

def genNcents(n,status):
    count = 0

    while (n < status and n != 0):
        status = getnextstatus(status)

    if (n == 0):
        return 1
    else:
        if (n >= 25 and status == 25):
            count = count + genNcents(n-25,status)
            status = getnextstatus(status)

        if (n >= 10 and status == 10):
            count = count + genNcents(n-10,status)
            status = getnextstatus(status)

        if (n >= 5 and status == 5):
            count = count + genNcents(n-5,status)
            status = getnextstatus(status)

        if (n >= 1 and status == 1):
            count = count + genNcents(n-1,status)
    
    return count

# main()
print sys.getrecursionlimit()
#sys.setrecursionlimit(2000)

n = int(raw_input())
count = genNcents(n,25)
print count
