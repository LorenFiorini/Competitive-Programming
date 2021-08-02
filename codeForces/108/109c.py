#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
import math



def solve ():
    n = int(input())
    u = list(map(int, input().split()))
    s = list(map(int, input().split()))

    print(n)
    print(u)
    print(s)





def main():
    t = int(input())
    while t > 0:
        solve()
        t -= 1

if __name__ == "__main__":
    main()