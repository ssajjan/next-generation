#!/usr/bin/python

"""
9.5
Write a method to compute all permutations of a string
7!/6! + 7!/5! + 7!/4! + 7!/3! + 7!/2! + 7!/1! + 7!/0!
7 + 42 + 210 + 840 + 2520 + 5040 + 5040 = 13699
List
"""

def insertch(subsetsB, charsetB, maxindex):
    copysubsetsB = subsetsB[:]
    for index in range(maxindex):
        for subset in copysubsetsB:
            copysub = subset[:]
            if (index < len(copysub)+1):
                copysub.insert(index,charsetB)
                if (copysub not in subsetsB):
                    subsetsB.append(copysub)

def genSubsets(setB,subsetsB,count):
    if (count == 0):
        subsetsB.append([])
    else:
        genSubsets(setB,subsetsB,count-1)
        insertch(subsetsB,setB[count-1],count)

# main()
strB = "1234aabc"
listB = strB[:]
setB = []
for b in listB:
    setB.append(b)
print setB

subsetsB = []
genSubsets(setB,subsetsB,len(setB))
for sub in subsetsB:
    strsub = ''
    for s in sub:
        strsub = strsub + s
    print strsub
#print subsetsB
print len(subsetsB)
