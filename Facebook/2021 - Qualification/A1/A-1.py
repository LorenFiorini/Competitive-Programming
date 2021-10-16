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
cin = open("a1(FULL-input).txt", 'r')
cout = open("a1-py(FULL-output).txt", 'w')

def isVowel(c):
	return (c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U')

def solve():
	s = cin.readline()
	s = list(s)
	mp = dict()
	
	n = len(s)
	for i in range(n-1):
		c = s[i]
		if c in mp:
			mp[c] += 1
		else:
			mp[c] = 1
	
	allV = 0
	allC = 0
	mxV = 0
	mxC = 0
	for c in mp:
		cnt = int(mp[c])
		if isVowel(c):
			mxV = max(mxV, cnt)
			allV += cnt
		else:
			mxC = max(mxC, cnt)
			allC += cnt
		#cout.write("\n"+str(cnt))
	
	ans = 0
	ans = min(allC + 2 * (allV - mxV) , allV + 2 * (allC - mxC))
	
	#cout.write(str(mp))
	#cout.write(str(allV) + " " + str(allC))
	return ans
	
def main():
	
	T = int(cin.readline())
	for _ in range(1, T+1):
		answer = solve()
		cout.write("Case #{}: {}\n".format(_, answer))
		
	

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
	cin.close()
	cout.close()
# Lorenzo Fiorini
