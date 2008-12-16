SUBDIRS = ncurses ncurses-c text text-c
.PHONY: clean
clean:
        @for i in $(SUBDIRS); \
	  do echo "Clearing in $$i..."; \
        (cd $$i; $(MAKE) $(MFLAGS) clean); \
	  done