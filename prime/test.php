#!/usr/bin/env php
<?php
	//TODO use file() instead of current file read?? 
	// this file is licensed under the CMU licence.
	/* this file checks the prime checker with a few tests 
	* check 1 -> echoes results for -1 to 7 for manual inspection 
	* check 2 -> runs through list of primes and checks them all 
	*/
	echo "Running check 1; manual inspection required\n";
	for ( $i = -1; $i <= 7; ++$i )
	{
		echo "$i is ", exec("./primeA $i"), "\n";
	}
	//open the primelist file
	$primelist = fopen("primelist.txt", "r") or print ("unable to test primelist");
	echo "check the results now\n";
	fgets(STDIN);
	//check each line of primes until "false" is reached; check assume they are NOT prime
	$correct_output="prime";
	echo "Automated testing of known primes...";
	while(!feof($primelist))
  	{
		$line = fgets($primelist);
		if ($line == "false\n")
		{
			$correct_output="not prime";
			echo "\n testing of primes complete; testing composites\n";
			//restart collection with the next set of composite numbers
			continue;
		}
		elseif ($line == "end\n")
		{
			echo "\n test 2 is over";
			break;
		}
		elseif ($line == "true\n")
		{
			// we already know this
			continue;
		}	
		$list = explode(' ',$line);
		foreach ($list as $i)
		{
			if (!empty($i) && $i!="\n")
			{
				$test = exec("./primeA $i");
				if ($test == $correct_output)
				{
					echo "$i...";
				}
				else
				{
					echo "test failed on $i";
					$error = true;
					break;
				}
			}
			if ($error)
			{
				break;
			}
		}
		echo "\n";
		if ($error)
		{
			break;
		}
  	}

	fclose($primelist);

	//this returns to STDERR so ignore the test for now
	/*
	echo "Test 3 (testing empty input)...";
	$test = exec("./primeA");
	if ($test == "sorry")
	{
		echo "passed";
	}
	else
	{
		echo "failed";
	}
	*/
?>