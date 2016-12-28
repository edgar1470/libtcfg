# Include the definition of tool chain
-include ./toolchain.def

SUBDIRS += libtcfg
SUBDIRS += example

COMMAND =	@set fnord $$MAKEFLAGS; amf=$$2; \
	target=`echo $@ | sed s/-recursive//`; \
	list='$(SUBDIRS)'; for subdir in $$list; do \
	  if test -f $$subdir/Makefile; \
	  then \
		  echo "Making $$target in $$subdir"; \
		  (cd $$subdir && $(MAKE) $(AM_MAKEFLAGS) $$target) \
		   || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; \
	  fi; \
	done;

all:
	+$(COMMAND)

clean:
	+$(COMMAND)

release:
	tar -cv
