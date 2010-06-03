#!/usr/bin/env ruby
debug = false
files = []
/* loop through ARGV and add files to array;*/
ARGV.each { 	
	|arg|
	if arg != "-debug"
		files.push(arg)
	else
		debug = true;
	end
}
/* loop through files and check for their existance */
files.each {
	|curfile|
	begin 
#I could also use File.exist?(file_name)
		File.new(curfile)
		$stderr.puts("fatal error: " + curfile + " exists")
	rescue
		if debug
			puts("starting execution of " + curfile + " ...")
                  puts("we are done")
		end
	end
}