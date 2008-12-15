.ifdef $(LANG) == c++
incFile = ../../cpp.Makefile
.elif $(LANG) == c
incFile = ../../c.Makefile
.endif

.include <$(incFile)>

NAME = hanoi
