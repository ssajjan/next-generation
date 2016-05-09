#!/usr/bin/python

"""
9.8
Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5 cents)
and pennies (1 cent), write code to calculate the number of ways of representing n
cents
"""

def getnextstatus(status):
    if (status == 25):
        return 10
    elif (status == 10):
        return 5
    elif (status == 5):
        return 1

def genNcents(n,ncentsets,ncentstr,status):
    while (n < status and n != 0):
        status = getnextstatus(status)

    if (n == 0):
        ncentsets.append(ncentstr)
    else:
        if (n >= 25 and status == 25):
            genNcents(n-25,ncentsets,ncentstr + 'q',status)
            status = getnextstatus(status)

        if (n >= 10 and status == 10):
            genNcents(n-10,ncentsets,ncentstr + 'd',status)
            status = getnextstatus(status)

        if (n >= 5 and status == 5):
            genNcents(n-5,ncentsets,ncentstr + 'n',status)
            status = getnextstatus(status)

        if (n >= 1 and status == 1):
            genNcents(n-1,ncentsets,ncentstr + 'p',status)

# main()
n = int(raw_input())
ncentsets = []
ncentstr = ''
genNcents(n,ncentsets,ncentstr,25)
#print ncentsets
for subset in ncentsets:
    print subset
