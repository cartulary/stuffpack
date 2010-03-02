#include <stdio.h>
#include <magic.h>
#include <err.h>

// if argc == 1 then stdin is used - how odd...
int main(int argc, char* argv[])
{
	const char *mstring, *merror;
	magic_t m;

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
