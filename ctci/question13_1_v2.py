#!/usr/bin/python

'''
13.1 Write a method to print the last K lines of an input file using C++
'''

try:
    with open("/tmp/randomlist.txt",'r') as f_input:
        if f_input is not None:
            f_input.seek(0,2)
            if (f_input.tell() != 0):
                f_input.seek(-2,2)
                count = 0
                while (count != 10):
                    if (f_input.tell() < 2):
                        f_input.seek(0,0)
                        break
                    else:
                        f_input.seek(-2,1)
                        if (f_input.read(1) == "\n"):
                            count = count+1

                while (count >= 0):
                    print f_input.readline(),
                    count = count-1
            else:
                print "File is empty"
        else:
            print "Error in opening file"
except:
    print "No such file exists"
