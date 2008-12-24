#!/usr/local/bin/ruby
debug = false
files = []
ARGV.each { 	
	|arg|
	if arg != "-debug"
		files.push(arg)
	else
		debug = true;
	end
}

files.each {
	|curfile|
	begin 
		File.new(curfile)
		$stderr.puts("fatal error: " + curfile + " exists")
	rescue
		if debug
			puts("starting execution of " + curfile + " ...")
                  puts("we are done")
		end
	end
}