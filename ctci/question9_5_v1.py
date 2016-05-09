#!/usr/bin/python

"""
9.5
Write a method to compute all permutations of a string
7!/6! + 7!/5! + 7!/4! + 7!/3! + 7!/2! + 7!/1! + 7!/0!
7 + 42 + 210 + 840 + 2520 + 5040 + 5040 = 13699
Needs hash table to count character's occurences
"""

def genSubsets(setB,subsetsB,count):
    if (count == 1):
        for char in setB:
            subsetsB.append(char)
    else:
        genSubsets(setB,subsetsB,count-1)
        copysubsetsB = subsetsB[:]
	for char in setB:
            for subchar in copysubsetsB:
                if char not in subchar:
                    if ((char+subchar) not in subsetsB):
                        subsetsB.append(char+subchar)

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
    print sub
#print subsetsB
print len(subsetsB)
