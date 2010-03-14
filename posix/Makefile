#we want to include the makefile depending on which target (and therefore
#which file) we use
.ifmake dirclean
NAME=XXX
.include <../Makefile>
SUBDIRS!= ls -F|grep \/
.else
.include <../../Makefile>
.endif


dirclean: .NOTMAIN
	for d in $(SUBDIRS); do \
		echo "Cleaning... $$d"; \
		make -C $$d clean; \
	done