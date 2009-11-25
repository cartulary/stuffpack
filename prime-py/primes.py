#!/usr/bin/env -S python -tt3 -Wd

# We want to test to see if our argument list is prime.

from math import sqrt
import sys;

def isPrime(num):
	if num < 2:
		return False;
	if num % 2 == 0:
		return False;
	for i in range(3, num):
		if num % i == 0:
			return False;
	return True;

for arg in sys.argv:
	if arg != sys.argv[0]:
		print isPrime(int(arg));
