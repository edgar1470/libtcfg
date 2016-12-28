# Include the definition of tool chaina
ROOT_DIR = ..
-include $(ROOT_DIR)/toolchain.def

GOAL = example

CFLAGS += -Wall
CFLAGS += -I$(ROOT_DIR)/libtcfg
CFLAGS += -I.

OBJS += example.o

LIBS += $(ROOT_DIR)/libtcfg/libtcfg.a

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
ifneq ($(DEBUG_ON),1)
	$(STRIP) $(GOAL)
endif

$(GOAL): $(OBJS) $(LIBS)
	$(MSG_SPLIT_LINE)
	@$(CC)  $(CFLAGS) -o $(GOAL) $(OBJS) $(LIBS) $(LDFLAGS)
	$(MSG_GOAL_OK)

.PHONY: clean
clean:
	$(MSG_SPLIT_LINE)
	rm -f $(OBJS:.o=.d) $(OBJS) $(GOAL)

-include $(OBJS:.o=.d)
