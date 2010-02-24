#!/usr/bin/env gdc

import std.stdio, std.file, std.path;

int main(string[] args)
{
	bool doDebug = false;
	string[] filesToCheck = new string[args.length];
	int numFiles =0;
	foreach (string arg; args[1 .. args.length])
	{
		if (arg == "-debug")
		{
			doDebug = true;
		}
		else
		{
			filesToCheck[numFiles] = arg;
			++numFiles;
		}
	}


	foreach(string file; filesToCheck[0 .. args.length])
	{
		if (file=="")
		{
			//we are empty so leave the loop...
			break;
		}
		if (file.exists())
		{
			//this should be written to standard error but I don't know how
			writefln("fatal error: %s exists", file);
		}
		else if(doDebug)
		{
			writefln("starting execution of %s ...\nwe are done",file);
		}
	}

	//do I need to use delete[] ??
	delete filesToCheck;
	return 0;
}
