DIST = fltk
DISTPATH = fltk
NAME=main
.include    <../Makefile.inc>

EXTRA_CFLAGS != fltk-config --use-forms --cxxflags --libs
CFLAGS += $(EXTRA_CFLAGS)

EXTRA_LDFLAGS != fltk-config --use-forms --ldflags --libs
LDFLAGS += $(EXTRA_LDFLAGS)

main:
	fltk2-config --compile main.cpp

#main: inputWindow.cpp ../hanoi.cpp main.cpp

#inputWindow.o:

clean: nameclean coreclean objclean
