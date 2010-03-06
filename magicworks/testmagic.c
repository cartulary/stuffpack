#include <stdio.h>
#include <magic.h>
#include <err.h>
#include <sysexits.h>

int main(int argc, char* argv[])
{
	const char *mstring, *merror;
	magic_t m;
	if (argc == 1)
	{
		errx(EX_USAGE, "Requires filename as first argument");
	}

	m = magic_open(MAGIC_SYMLINK | MAGIC_ERROR);
	magic_load(m,"/usr/share/misc/magic");

	mstring = magic_file(m,argv[1]);
	merror = magic_error(m);

	if (merror)
		errx(1, "%s\n", merror);
	printf("%s\n", mstring);
	magic_close(m);
	return 0;
}
