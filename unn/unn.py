#!/usr/local/bin/python
import os;
import sys;

debug = False;
files = [];
for arg in sys.argv:
	if (arg == "-debug"):
		debug = True;
	else:
		if (not (arg == sys.argv[0])):
			files.append(arg);

for file in files:
	if (os.path.exists(file)):
		toOut = "fatal error: ";
		toOut += file;
		toOut += " exists\n";
		sys.stderr.write (toOut);
	else:
		if (debug):
			print "starting execution of ",file," ...";
			print "we are done";