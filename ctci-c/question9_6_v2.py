#!/usr/bin/python

"""
9.6
Implement an algorithm to print all valid (i.e., properly opened and closed) combi-
nations of n-pairs of parentheses.
Tried to do with list, think string being immutable wont change. Immutability makes a new variable
so using that logic!
"""

def genparentheses(sets,strs,n,leftp,rightp,index):
    if (leftp == 0 and rightp == 0):
        print sets,strs[index],id(strs[index])
        sets.append(strs[index])
    else:
        if (leftp > 0):
            print 1,strs[index],id(strs[index])
            strs[index].append("(")
            print 2,strs[index],id(strs[index])
            genparentheses(sets,strs,n,leftp-1,rightp,index)

        if (leftp > 0):
            print n,leftp,strs[index]
            strs[index] = strs[index][:n-1]

        if (rightp > leftp):
            print 3,strs[index],id(strs[index])
            strs[index].append(")")
            print 4,strs[index],id(strs[index])
            genparentheses(sets,strs,n,leftp,rightp-1,index)
        

# main()
n = 3
sets = []
strs = [[],[],[],[],[],[]]
genparentheses(sets,strs,n,n,n,0)
print sets
