#!/usr/bin/python

#global variable
fib = [0]*100

def fibonacci(i):
    print (i,fib[i])
    if (i == 0): 
        return 0
    if (i == 1): 
        return 1

    if (fib[i] != 0): 
        return fib[i]
    
    print "Before"
    fib[i] = fibonacci(i - 1) + fibonacci(i - 2)
    print "After"
    print "--------"

    return fib[i]

#main()
print fibonacci(5)
