divisbleBy :: Int -> Int -> Bool
divisbleBy = ((==0).) . mod
fb :: Int -> String
fb x
	| divisbleBy x 3 && divisbleBy  x 5 = "fizzbuzz"
	| divisbleBy x 3 = "fizz"	
	| divisbleBy x 5 = "buzz"	
	| otherwise = show x
	
main = mapM_ putStrLn  [ fb x | x <- [ 1..20] ]
