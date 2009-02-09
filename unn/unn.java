import java.util.ArrayList;
import java.util.Iterator;
import java.io.File;

public class unn
{
	public static void main(String[] args)
	{
		Boolean debug = Boolean.FALSE;
		ArrayList files = new ArrayList();
		Iterator filesIt;

		/* loop through the various command line arguments and add them to the file array */
		for (String arg : args)
		{
			if (!arg.equals("-debug"))
			{
				files.add(arg);
			}
			else
			{
				/* someone enabled debug */
				debug = Boolean.TRUE;
			}
		}
		/* iterate through the files and run the checks */
		filesIt = files.iterator();
		String file;
		File f;
		while (filesIt.hasNext())
		{
			file = filesIt.next().toString(); 
    			f = new File(file);
			/* check to see if the file exists */
			if (f.exists())
			{
				System.err.println("fatal error: " + file + " exists");
			}
			else
			{
				if (debug)
				{
					/* only echo information if we have debug enabled */
					System.out.println("starting execution of " + file + " ...");
					System.out.println("we are done");

				}
			}
		}
   	}
}
