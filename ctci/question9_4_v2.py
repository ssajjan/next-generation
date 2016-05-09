#!/usr/bin/python

"""
9.4
Write a method to return all subsets of a set.
"""

def printSubsets(setA):

    count = 0
    for subset in setA:
        count = count + 1
        print (subset),
    print count

    count = 0
    for subset1 in setA:
        for subset2 in setA:
            if (subset2 != subset1):
                count = count + 1
                print (subset1,subset2),
    print count

    count = 0
    for subset1 in setA:
        for subset2 in setA:
            if (subset2 != subset1):
                for subset3 in setA:
                    if (subset3 != subset1 and subset3 != subset2):
                        count = count + 1
                        print (subset1,subset2,subset3),
    print count

    count = 0
    for subset1 in setA:
        for subset2 in setA:
            if (subset2 != subset1):
                for subset3 in setA:
                    if (subset3 != subset1 and subset3 != subset2):
                        for subset4 in setA:
                            if (subset4 != subset1 and subset4 != subset2 and subset4 != subset3):
                                count = count + 1
                                print (subset1,subset2,subset3,subset4),
    print count
# main()
setA = [1,2,3,4,'a','b','ab']

printSubsets(setA)
