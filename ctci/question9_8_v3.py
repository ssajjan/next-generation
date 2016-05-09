#!/usr/bin/python

"""
9.8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents)
and pennies (1 cent), write code to calculate the number of ways of representing n
cents
"""

def makeChange(n,denom):
    next_denom = 0;
    '''
    switch (denom):
        case 25:
            next_denom = 10;
            break;
        case 10:
            next_denom = 5;
            break;
        case 5:
            next_denom = 1;
            break;
        case 1:
            return 1;
    int ways = 0;
    for (int i = 0; i * denom <= n; i++) {
        ways += makeChange(n - i * denom, next_denom);
    }
    '''
    if (denom == 25):
        next_denom = 10
    elif (denom == 10):
        next_denom = 5
    elif (denom == 5):
        next_denom = 1
    elif (denom == 1):
        return 1

    ways = 0;
    i = 0
    while (i*denom <= n):
        ways = ways + makeChange(n - i*denom, next_denom);
        i = i+1

    return ways;

# main()
n = int(raw_input())
print makeChange(n,25)
