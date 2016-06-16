#!/usr/bin/python

"""
9.5
Write a method to compute all permutations of a string
7!/6! + 7!/5! + 7!/4! + 7!/3! + 7!/2! + 7!/1! + 7!/0!
7 + 42 + 210 + 840 + 2520 + 5040 + 5040 = 13699
String
"""

def insertch(subsetsB, charB, maxindex):
    copysubsetsB = subsetsB[:]
    for sub in copysubsetsB:
        for index in range(len(sub)+1):
            copysub = sub
            copysub = copysub[:index] + charB + copysub[index:]
            if (copysub not in subsetsB):
                subsetsB.append(copysub)

def genSubsets(strB,subsetsB,count):
    if (count == 0):
        subsetsB.append("")
    else:
        genSubsets(strB,subsetsB,count-1)
        insertch(subsetsB,strB[count-1],count)

# main()
strB = "123"
subsetsB = []
genSubsets(strB,subsetsB,len(strB))
#print subsetsB
for subset in subsetsB:
    print subset
print len(subsetsB)
