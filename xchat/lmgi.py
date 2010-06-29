#!/usr/bin/env python

__module_name__ = "let me google that for you (/lmgi)"
__module_version__ = "0.9"
__module_description__ = "Operates google for you"

import xchat
import urllib

print "\0034",__module_name__, __module_version__,"loading...\003"
def letmegoogleit(word, word_eol, userdata):
	if len(word) < 2:
		print ("Choose something to google for");
		return;
	wordStr = "+".join(word[1:])
	print "googling for "+wordStr
	endUrl = urllib.urlopen('http://tinyurl.com/api-create.php?url=http://letmegooglethatforyou.com?q='+wordStr).read()
	print endUrl
	xchat.command("PRIVMSG " +  xchat.get_info("channel") + " " + endUrl)

xchat.hook_command('lmgi', letmegoogleit, help="pick your search terms and type /lmgi terms")
