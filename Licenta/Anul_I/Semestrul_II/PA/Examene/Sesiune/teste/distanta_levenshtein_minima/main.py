#!/usr/bin/env python3
# -*- coding: utf-8 -*-


def main():
    a = input("First :")
    b = input("First :")

    m = max(len(a), len(b)) + 1
    d = [[0 for j in range(m)] for i in range(m)]


    for i in range(m):
        d[0][i] = i
        d[i][0] = i

    print(d)

    for i in range(1,len(a)):
        for j in range(1,len(b)):
            if a[i] == b[i]:
                d[i][j] = min(d[i-1][j] + 1,
                            d[i][j-1] + 1,
                            d[i-1][j-1] ) # sunt egale deci nu facem nici o aduagare
            else:
                d[i][j] = min( d[i-1][j] + 1,
                            d[i][j-1] + 1,
                            d[i-1][j-1] + 1 ) # nu sunt egale deci adaugam

    print("pasi sunt ", d[len(a)-1][len(b)-1])
    for line in d:
        print(line)


if __name__ == "__main__":
    main()
