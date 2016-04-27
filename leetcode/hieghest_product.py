product = lambda arr: reduce(lambda x,y: x*y, arr, 1)

def highest_product_of_n_optimal(array_of_ints, n=3):

    if len(array_of_ints) < n: raise Exception("Less than %d items!" % n)

    highest_product = [product(array_of_ints[:i]) for i in range(2, n+1)]
    lowest_product = [product(array_of_ints[:i]) for i in range(2, n+1)]

    highest_product.insert(0, max(array_of_ints[:n-1]))
    lowest_product.insert(0, min(array_of_ints[:n-1]))

    for current in array_of_ints[n-1:]:

        for i in range(len(highest_product)-1, 0, -1):

            highest_product[i] = max(
                highest_product[i],
                current * highest_product[i-1],
                current * lowest_product[i-1],
            )

            lowest_product[i] = min(
                lowest_product[i],
                current * highest_product[i-1],
                current * lowest_product[i-1],
            )

        highest_product[0] = max(highest_product[0], current)
        lowest_product[0] = min(lowest_product[0], current)

    return highest_product[-1]
