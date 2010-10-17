#!/usr/bin/env python

__module_name__ = "let me search that for you (/lmgi /ddg /bing /jgi /sbit)"
__module_version__ = "1.0"
__module_description__ = "Operates search engines for you"

import xchat
import string
import urllib


#Url Shortners
TINYURL_API_URL="http://tinyurl.com/api-create.php?url=[url]"

#Let me * it for you sites
GOOGLE_FOR_YOU="http://letmegooglethatforyou.com?q=[term]"
DDG_FOR_YOU="http://lmddgtfy.com/?q=[term]"
BING_FOR_YOU="http://www.letmebingthatforyou.com/?q=[term]"
SEARCHBAR_FOR_YOU="http://lmsbtfy.com/?q=[term]"
JUST_GOOGLE_FOR_YOU="http://www.justfuckinggoogleit.com/search.pl?query=[term]"

#other constants
HELP_TEXT = "pick your search terms and type /[site] terms"

print "\0034",__module_name__, __module_version__,"loading...\003"

def getTinyUrl(searchEngine, searchTerms, turlApiURL):
	finalUrl = searchEngine.replace("[term]",searchTerms)
	finalUrl = turlApiURL.replace("[url]",finalUrl)
	return finalUrl

def doWork(word, searchEngine):
	if len(word) < 2:
		print ("Choose something to search for");
		return;
	wordStr = "+".join(word[1:])
	wordStr = string.strip(wordStr)
	print "serching for "+wordStr
	tinyUrl=getTinyUrl(searchEngine,wordStr,TINYURL_API_URL)
	endUrl = urllib.urlopen(tinyUrl).read()
	print endUrl
	xchat.command("PRIVMSG " +  xchat.get_info("channel") + " " + endUrl)
	

def letmegoogleit(word, word_eol, userdata):
	doWork(word, GOOGLE_FOR_YOU)

def letmeddgit(word, word_eol, userdata):
	doWork(word, DDG_FOR_YOU)

def letmebingit(word, word_eol, userdata):
	doWork(word, BING_FOR_YOU)

def letmesbit(word, word_eol, userdata):
	doWork(word, SEARCHBAR_FOR_YOU)

def justGoogleIt(word, word_eol, userdata):
	doWork(word, JUST_GOOGLE_FOR_YOU)

xchat.hook_command('lmgi', letmegoogleit, HELP_TEXT.replace("[site]","lmgi"))
xchat.hook_command('ddg', letmeddgit, HELP_TEXT.replace("[site]","ddg"))
xchat.hook_command('bing', letmebingit, HELP_TEXT.replace("[site]","bing"))
xchat.hook_command('sbit', letmesbit, HELP_TEXT.replace("[site]","sbit"))
xchat.hook_command('jgi', justGoogleIt, HELP_TEXT.replace("[site]","jgi"))
