#we want to include the makefile depending on which target (and therefore
#which file) we use
.ifmake dirclean
.include <../Makefile>
.else
.include <../../Makefile>
.endif

SUBDIRS!= ls -F|grep \/

dirclean: .NOTMAIN
	for d in $(SUBDIRS); do \
		echo "Cleaning... $$d"; \
		make -C $$d clean; \
	done