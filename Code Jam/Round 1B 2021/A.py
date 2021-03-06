#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase
# Imports
import math


if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

#-----------------------------------------------------------------------

""""
def check(i, j, k, v):
	a = v[i]
	b = v[j]
	c = v[k]
	A = a
	B = b
	C = c
	ans = [0,0,0,0,False]
	p = 0
	while not ans[4] and p < 3:
		ans = che (A, B, C)
		if ans[4]:
			return ans
		
		A = a - v[p]
		B = b - v[p]
		C = c - v[p]
		
		if A < 0:
			mod = (A-1) % (432 * pow(10, 11))
			A %= (432 * pow(10, 11)) - mod
		if B < 0:
			mod = (B-1) % (432 * pow(10, 11))
			B %= (432 * pow(10, 11))- mod
		if C < 0:
			mod = (C-1) % (432 * pow(10, 11))
			C %= (432 * pow(10, 11)) - mod
		p += 1
	return ans"""

def check(i, j, k, v):
	
	a = v[i]
	b = v[j]
	c = v[k]
	
	nan = 0
	cor = int(0)
	""""a //= (36 * pow(10, 11))
	b //= (5 * pow(10, 9))
	c //= (1388889)"""
	
	if b % 12 != 0 or c % 720 != 0:
		cor = int(12 - (b % 12))
		corr = int(720 - (c % 720))
		if cor != corr:
			return [0, 0, 0, 0, False]
	a += cor
	b += cor
	c += cor
	nan = c // 720
	if a == nan and b // 12 == nan: #and c // 720 == nan:
		# TICKS
		
		H = a // (36 * pow(10, 11))
		M = b // (6 * pow(10, 10))
		S = c // (72 * pow(10, 10))
		
		return [H, M, S, nan, True]
		
	return [0, 0, 0, 0, False]



def solve(CASE):
	n = list(map(int, input().split()))
	#print(n)
	H = int()
	M = int()
	S = int()
	nan = int()
	while True:
		for i in range(0, 3):
			for j in range(0, 3):
				if i == j:
					continue
				for k in range(0, 3):
					if i == k or j == k:
						continue
					
					li = check(i, j, k, n)
					
					
					if li[4]:
						print("Case #{}: {} {} {} {}".format(CASE, li[0], li[1], li[2], li[3]))
						return
		for i in range(3):
			n[i] += 720
			if n[i] == 360 * 12 * pow(10, 10):
				n[i] = 0
		
	


def main():
	t = int(input())
	for _ in range(t):
		solve(_ + 1)
	

#-----------------------------------------------------------------------
# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

input = lambda: sys.stdin.readline().rstrip("\r\n")

# endregion

if __name__ == "__main__":
    main()
