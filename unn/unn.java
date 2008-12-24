import java.util.ArrayList;
import java.util.Iterator;
public class unn
{
	public static void main(String[] args)
	{
		Boolean debug = false;
		ArrayList files = new ArrayList();
		Iterator filesIt;

		for (String arg : args)
		{
			if (arg != "-debug")
			{
				files.add(arg);
			}
			else
			{
				debug = true;
			}
		}
		filesIt = files.iterator();
		String file;
		while (filesIt.hasNext())
		{
			file = filesIt.next().toString(); 
			if (debug==true)
			{
				System.out.println("starting execution of " + file + " ...");
				System.out.println("we are done");

			}
			System.out.println(file);
		}
   	}
}
