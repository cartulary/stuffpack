CFLAGS := -g3 -pipe

.ifdef $(LANG) == c++
#we are using c++ add the flags that only work for c++
CC := llvm-g++
CFLAGS += -ansi -Wabi
CFLAGS += -Weffc++
CFLAGS += -fno-gnu-keywords
CFLAGS += -Wstrict-null-sentinel -Wctor-dtor-privacy -Wnon-virtual-dtor -Woverloaded-virtual -Wsign-promo
CFLAGS += -ffor-scope
.elif $(LANG) == c
CC := llvm-gcc
CFLAGS += -g
CFLAGS += -std=c99 
CFLAGS += -Wimplicit-function-declaration -Wbad-function-cast -Wdeclaration-after-statement
.endif
# set the global flags
CFLAGS += -Wall -Wextra -pedantic
CFLAGS += -Wformat=2 -Wformat-y2k -Wformat-nonliteral -Wformat-security
CFLAGS += -Wunused -Wunused-parameter
CFLAGS += -Winit-self -Wmissing-include-dirs -Wfloat-equal
CFLAGS += -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wcast-align
CFLAGS += -fabi-version=0 -funroll-loops
CFLAGS += -Wunreachable-code -Winline

PREFIX = /usr/local

superclean: .NOTMAIN
	rm -rfv ./$(NAME)