#!/usr/bin/env -S python3.1 -Wd

# Takes a word or phraseand tells you if it is a palindrome
# Ignores punctuation or case

def isPalindrome(word):
	word=word.lower();
	word = [ letter for letter in word if letter.isalpha() ]
	return word == word[::-1];

print (isPalindrome("aba."));
print (isPalindrome("a.a"));
print (isPalindrome(".azzz"));
