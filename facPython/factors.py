#!/usr/bin/python3
def prime_factorization():
    from sys import argv
    with open(argv[1], "r") as facfile:
        lines = facfile.readlines() 
        for n in lines:
            n = int(n)
            for p in range(2, n):
                if n % p == 0:
                    q = n // 2
                    print("{} = {} * {}".format(n, q, p))
                    break
prime_factorization()
