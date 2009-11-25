#!/usr/bin/env -S python -tt3

# We want to test to see if our argument list is prime.

from math import sqrt
import sys;

def isPrime(num):
	for i in range(3, int(sqrt(num)) + 1):
		if num % i == 0:
			return False
	return True

for arg in sys.argv:
	if arg != sys.argv[0]:
		print isPrime(int(arg));
