import System.Environment
import System.IO
import System.Directory


parseUnn :: String -> IO String
parseUnn fileName = do
	fileExists <- doesFileExist fileName
	if fileExists
		then return ("fatal error: " ++ fileName ++ ": File exists\n")
		else return ""

main = do
	(fileNames) <- getArgs
	case fileNames of
		[] -> error "you used it wrong, idiot!"
		_ -> mapM_ (\filename -> parseUnn filename >>= putStr) fileNames
		 
