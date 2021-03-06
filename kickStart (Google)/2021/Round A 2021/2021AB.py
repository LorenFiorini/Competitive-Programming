#!/usr/bin/env python
from __future__ import division, print_function

import os
import sys
from io import BytesIO, IOBase
# Imports
import numpy

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

#-----------------------------------------------------------------------


def showmat(mat):
	print()
	for i in range(len(mat)):
		for j in range(len(mat[0])):
			print("{}".format(mat[i][j]), end = " ")
		print()
	

def count(mat, R, C):
	ans = 0
	prerow = [[0 for i in range(C)] for j in range(R)]
	precol = [[0 for i in range(C)] for j in range(R)] 
	
	for i in range(R):
		for j in range(C):
			prerow[i][j] = mat[i][j]
			precol[i][j] = mat[i][j]
			if mat[i][j] == 1 and j > 0:
				prerow[i][j] += prerow[i][j-1]
			if mat[i][j] == 1 and i > 0:
				precol[i][j] += precol[i-1][j]
	
	for i in range(R):
		for j in range(C):
			if prerow[i][j] >= 2 and  precol[i][j] >= 4:
				ans += min(prerow[i][j] - 1, (precol[i][j] // 2) - 1)
			if prerow[i][j] >= 4 and  precol[i][j] >= 2:
				ans += min(precol[i][j] - 1, (prerow[i][j] // 2) - 1)
	
	return ans

def solve(_):
	R, C = input().split()
	R = int(R)
	C = int(C)
	mat = list()
	for i in range(R):
		row = list(map(int, input().split()))
		mat.append(row)
	
	answ = count(mat, R, C)
	mat = numpy.flipud(mat)
	answ += count(mat, R, C)
	mat = numpy.flip(mat)
	answ += count(mat, R, C)
	mat = numpy.flipud(mat)
	answ += count(mat, R, C)
	
	print("Case #{}: {}".format(_, answ))


def main():
	t = int(input())
	for _ in range(1, t + 1):
		solve(_)


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
