# We want to test to see if our argument list is prime.

from math import sqrt

def isPrime(num):
	for i in range(3, int(sqrt(num))):
		if num % i == 0:
			return False
	return True

print isPrime(11);
print isPrime(12);