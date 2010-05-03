import static java.lang.System.out;
import java.io.IOException;
import java.util.*;

class hangman {
  public static void main(String[] args) {
		final int maxBadGuess = 7;

		String[] words = { "apple", "bannana", "power", "reality", "computer" };

		Random randomGenerator = new Random();
		int wordID = randomGenerator.nextInt(words.length);
		List<Character> guessed = new ArrayList<Character>();
		Boolean gameover = false;
		String word = words[wordID];
		out.println("The word is: " + word);
		Character c = 0;
		final Character newline = '\n';
		int badGuesses = 0;
		try {
			while(!gameover) {
 				c = (char)System.in.read();
				Character guess = c;
				if (newline.charValue() == c)
				{
					continue;
				}
				if (guessed.contains(c))
				{
					out.println("You already guessed that.");
					continue;
				}
				guessed.add(c);
				if (checkWin(word,guessed))
				{
					out.println("You won!");
					gameover = true;
				}
				if (-1 == word.indexOf(c))
				{
					++badGuesses;
				}
				if (maxBadGuess == badGuesses)
				{
					out.println("You lost");
					gameover = true;
				}
				out.println("Total guesses:" + guessed.size() + " deaths: " + Integer.toString(maxBadGuess - badGuesses));
				printBoard(badGuesses);
			}
		}
		catch (IOException e) {
			out.println("Something bad happend:" + e.getMessage());
			out.println("Caused by: " + e.getCause());
		}

  }

	private static Boolean checkWin(String word, List<Character> guesses)
	{
		for (Character c : word.toCharArray())
		{
			if (!guesses.contains(c))
			{
				return false;
			}
		}
		return true;
	}

	private static void printBoard(int deaths)
	{
		out.println ("_____________  ");
		out.println ("|           |  ");
		// head
		if (deaths == 0)
		{
            out.println ("|               "); 
            out.println ("|               "); 
            out.println ("|               "); 
            out.println ("|               "); 
		}
		else
		{
            out.println ("|           o   "); 
            out.println ("|          o o  "); 
            out.println ("|          o o  "); 
            out.println ("|           o   "); 
        }
		// body & arms
		if (deaths == 1)
		{
            out.println ("|               "); 
            out.println ("|               "); 
            out.println ("|               "); 
		}
		else if (deaths == 2)
		{
            out.println ("|           |    "); 
            out.println ("|           |    "); 
            out.println ("|           |    "); 
		}
		else if (deaths == 3)
		{
            out.println ("|           |    "); 
            out.println ("|          /|    "); 
            out.println ("|         / |    "); 
		}
		else if (deaths >= 4)
		{
            out.println ("|           |    "); 
            out.println ("|          /|\\  "); 
            out.println ("|         / | \\ "); 
		}

		//legs

		if (deaths <= 4)
		{
            out.println ("|                ");
            out.println ("|                ");
            out.println ("|                ");
		}
		else if (deaths == 5)
		{
            out.println ("|           |    ");
            out.println ("|           |    ");
            out.println ("|           |    ");
		}
		else if (deaths == 6)
		{
            out.println ("|           |    ");
            out.println ("|          /|    ");
            out.println ("|         / |    ");
		}
		else if (deaths == 7)
		{
            out.println ("|           |    ");
            out.println ("|          /|\\  ");
            out.println ("|         / | \\ ");
		}
		out.println ("|________________");
	}
}
