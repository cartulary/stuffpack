#!/usr/bin/env python

__module_name__ = "let me search that for you (/lmgi or /ddg)"
__module_version__ = "0.9"
__module_description__ = "Operates search engines for you"

import xchat
import urllib

TINYURL_API_URL="http://tinyurl.com/api-create.php?url=[url]"
GOOGLE_FOR_YOU="http://letmegooglethatforyou.com?q=[term]"
DDG_FOR_YOU="http://lmddgtfy.com/?q=[term]"

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
	print "serching for "+wordStr
	tinyUrl=getTinyUrl(searchEngine,wordStr,TINYURL_API_URL)
	endUrl = urllib.urlopen(tinyUrl).read()
	print endUrl
	xchat.command("PRIVMSG " +  xchat.get_info("channel") + " " + endUrl)
	

def letmegoogleit(word, word_eol, userdata):
	doWork(word, GOOGLE_FOR_YOU)

def letmeddgit(word, word_eol, userdata):
	doWork(word, DDG_FOR_YOU)


xchat.hook_command('lmgi', letmegoogleit, help="pick your search terms and type /lmgi terms")
xchat.hook_command('ddg', letmeddgit, help="pick your search terms and type /ddg terms")
