#!/usr/bin/python

"""
9.6
Implement an algorithm to print all valid (i.e., properly opened and closed) combi-
nations of n-pairs of parentheses.
State of concatenated string and decremented variable maintained in each call
"""

def genparentheses(sets,strs,leftp,rightp):
    #print "Called",leftp,rightp

    if (leftp == 0 and rightp == 0):
        #print sets,strs,id(strs)
        sets.append(strs)
    else:
        if (leftp > 0):
            #print 1,strs,id(strs)
            #strs = strs + "("
            #leftp = leftp-1
            #print 2,strs,id(strs)
            #print "Left Calling",leftp-1,rightp
            genparentheses(sets,strs+"(",leftp-1,rightp)

        #if (leftp > 0):
        #print "Left",n,leftp,rightp,strs

        #if (rightp > 0):
        if (rightp > leftp):
            #print 3,strs,id(strs)
            #strs = strs + ")"
            #rightp = rightp-1
            #print 4,strs,id(strs)
            #print "Right Calling",leftp,rightp-1
            genparentheses(sets,strs+")",leftp,rightp-1)
        
        #if (rightp > 0):
        #print "Right",n,leftp,rightp,strs
    #print "End Called",leftp,rightp

# main()
n = 5
sets = []
strs = ""
genparentheses(sets,strs,n,n)
#print sets
for subset in sets:
    print subset
