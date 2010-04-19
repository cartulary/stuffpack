import static java.lang.System.out; import java.io.IOException; import java.util.*;

class hangman {
    public static void main(String[] args) {
		String[] words = { "apple", "bannana", "power", "reality", "computer" };

		Random randomGenerator = new Random();
		int wordID = randomGenerator.nextInt(words.length);
		List<Character> guessed = new ArrayList<Character>();
		Boolean gameover = false;
		String word = words[wordID];
		out.println("The word is: " + word);
		Character c = 0;
		try {
			while(!gameover) {
 				c = (char)System.in.read();
				Character guess = c;
				guessed.add(c);
				if (checkWin(word,guessed))
				{
					out.println("You won!");
					gameover = true;
				}
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
}
