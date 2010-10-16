#!/usr/bin/env python

__module_name__ = "let me DDG that for you (/ddg)"
__module_version__ = "0.9"
__module_description__ = "Operates duck duck go for you"

import xchat
import urllib

print "\0034",__module_name__, __module_version__,"loading...\003"
def letmeduckeit(word, word_eol, userdata):
	if len(word) < 2:
		print ("Choose something to ddg for");
		return;
	wordStr = "+".join(word[1:])
	print "DuckDuckGoing for "+wordStr
	endUrl = urllib.urlopen('http://tinyurl.com/api-create.php?url=http://lmddgtfy.com/?q='+wordStr).read()
	print endUrl
	xchat.command("PRIVMSG " +  xchat.get_info("channel") + " " + endUrl)

xchat.hook_command('ddg', letmeduckit, help="pick your search terms and type /ddg terms")

#I could probably generalize this to make it for /any/ letme*it website ....
