#!/usr/bin/python

"""
9.4
Write a method to return all subsets of a set.
"""

def genSubsets(setA,subsetsA,count):
    if (count == 0):
        subsetsA.append(" ")
    elif (count == 1):
        genSubsets(setA,subsetsA,count-1)
        subsetsA.append(str(setA[len(setA)-count]))
    else :
        genSubsets(setA,subsetsA,count-1)
        copysubsetsA = subsetsA[:]
	for i in range(len(copysubsetsA)):
            if (copysubsetsA[i] == " "):
                copysubsetsA[i] = str(setA[len(setA)-count])
            else:
                copysubsetsA[i] = copysubsetsA[i] + "," + str(setA[len(setA)-count])
            subsetsA.append(copysubsetsA[i])

# main()
setA = [1,2,3,4,'a','b','ab']
subsetsA = []
genSubsets(setA,subsetsA,len(setA))
print subsetsA
print len(subsetsA)
