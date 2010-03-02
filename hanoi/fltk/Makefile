DIST = fltk
DISTPATH = fltk
USE_FLTK=yes
.include    <../Makefile.inc>

main: inputWindow.cpp ../hanoi.cpp main.cpp
	fltk2-config --compile main.cpp
clean: objclean coreclean
	rm -f main