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

		for (String arg : args)
		{
			if (!arg.equals("-debug"))
			{
				files.add(arg);
			}
			else
			{
				debug = Boolean.TRUE;
			}
		}
		filesIt = files.iterator();
		String file;
		File f;
		while (filesIt.hasNext())
		{
			file = filesIt.next().toString(); 
    			f = new File(file);
			if (f.exists())
			{
				System.err.println("fatal error: " + file + " exists");
			}
			else
			{
				if (debug)
				{
					System.out.println("starting execution of " + file + " ...");
					System.out.println("we are done");

				}
			}
		}
   	}
}
