# Include the definition of tool chaina
ROOT_DIR = ..
-include $(ROOT_DIR)/toolchain.def

GOAL     = libtcfg.a

CFLAGS += -Wall
CFLAGS += -I.

OBJS += tcfg.o
#---------------------------------------------------------------------------
# Implicit rules
#---------------------------------------------------------------------------
.c.o:
	$(MSG_SPLIT_LINE)
	$(MSG_COMPILING)
	@$(CC) $(CFLAGS) -MM -MT $@ -o $*.d $<
	@$(CC) -c $(CFLAGS) -o $*.o $<

#---------------------------------------------------------------------------
# Explicit ruls
#---------------------------------------------------------------------------
all: $(GOAL)
	$(MSG_SPLIT_LINE)

$(GOAL): $(OBJS)
	$(MSG_SPLIT_LINE)
	@$(AR) r $(GOAL) $(OBJS)
	$(MSG_GOAL_OK)

.PHONY: clean
clean:
	$(MSG_SPLIT_LINE)
	rm -f $(OBJS:.o=.d) $(OBJS) $(GOAL)

-include $(OBJS:.o=.d)
