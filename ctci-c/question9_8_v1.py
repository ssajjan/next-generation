#!/usr/bin/python

"""
9.8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents)
and pennies (1 cent), write code to calculate the number of ways of representing n
cents
"""

def genNcents(n,ncentsets,ncentstr):
    if (n == 0):
        ncentstr = sorted(ncentstr)
        if ncentstr not in ncentsets:
            ncentsets.append(ncentstr)
    else:
        if (n-25 >= 0):
            genNcents(n-25,ncentsets,ncentstr + 'q')

        if (n-10 >= 0):
            genNcents(n-10,ncentsets,ncentstr + 'd')

        if (n-5 >= 0):
            genNcents(n-5,ncentsets,ncentstr + 'n')

        if (n-1 >= 0):
            genNcents(n-1,ncentsets,ncentstr + 'p')

# main()
n = 50
ncentsets = []
ncentstr = ''
genNcents(n,ncentsets,ncentstr)
#print ncentsets
for subset in ncentsets:
    print subset
