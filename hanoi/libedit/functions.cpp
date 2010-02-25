#include "../functions.h"
#include <histedit.h>

const char* prompt(EditLine *e);
const char* prompt(EditLine *e) {
	return "Enter a number: ";
}

long int getinteger(int base)
{
	EditLine *el;
	History *hist;

	int count;
	const char* line;
	bool gotint = false;
	HistEvent ev;

	el = el_init("hanoi", stdin, stdout, stderr);
	el_set(el, EL_PROMPT, &prompt);
	el_set(el, EL_EDITOR, "emacs");

	hist = history_init();
	if (!hist)
	{
		std::cerr << "Sorry - no history\n";
	}

	history(hist, &ev, H_SETSIZE, 5);

	el_set(el, EL_HIST, history, hist);

	int n;
	while (!gotint)
	{
		line = el_gets(el, &count);

		if (count > 0)
		{
			history(hist, &ev, H_ENTER, line);
		}
		n = strtol(line,NULL,base);
		if (n  >  0)
		{
			gotint=true;
		}
	}

	return n;
}
