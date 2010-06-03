#!/usr/bin/env python
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
		sys.stderr.write ("fatal error: " + file + " exists\n");
	else:
		if (debug):
			print "starting execution of ",file," ...";
			print "we are done";