def is_prime(n):
    return all([(n%j) for j in range(2, int(n**0.5)+1)]) and n>1


def fibonacci(n):
    start = 0
    i = 1
    for j in range(1,n,2):
        if start >0 and is_prime(start):print(j,start,"- ... \"BuzzFizz\"")
        elif start >0 and start%3==0:print(j,start,"- ... \"Buzz\"")
        elif start >0 and start%5==0:print(j,start,"- ... \"Fizz\"")
        else: print (j,start,"- ... ", start)

        if i>0 and is_prime(start):print(j+1,i,"- ... \"BuzzFizz\"")
        elif i>0 and i%3==0:print(j+1,i,"- ... \"Buzz\"")
        elif i>0 and i%5==0:print(j+1,i,"- ... \"Fizz\"")
        else: print (j+1,i,"- ... ", i)

        start += i
        i = start + i
        j=j+2



fibonacci(79)
