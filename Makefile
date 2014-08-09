SRC := src/
INC := include/
OBJ := obj/
BIN := bin/
LIB := lib/
MAN := man/

V ?= 1

MAJOR-VERSION:=0
MINOR-VERSION:=0
FIX-VERSION  :=0
VERSION      :=$(MAJOR-VERSION).$(MINOR-VERSION).$(FIX-VERSION)

CC      := gcc
CCFLAGS := -Wall -Wextra -pedantic -Werror
CSFLAGS := -fPIC -DNETIO_VERSION=\"$(VERSION)\"
LDFLAGS := 
LSFLAGS := -shared

NETIO_OBJECTS += context header device raw   # netio core
NETIO_OBJECTS += packet ipaddr macaddr       # netio api
NETIO_OBJECTS += arp ethernet ip udp         # netio protocols


MAKEFLAGS += -rR --no-print-directory

config-targets := clean .depends
ifeq ($(filter $(config-targets), $(MAKECMDGOALS)),)
  mode := build
else
  ifeq ($(filter-out $(config-targets), $(MAKECMDGOALS)),)
    mode := config
  else
    mode := mixed
  endif
endif


ifeq ($(mode),mixed)

%:: _FORCE
	@+$(MAKE) $@

.PHONY: _FORCE
_FORCE:

else


default: check


ifeq ($(mode),build)
  -include .depends
endif


.PHONY: all examples
all: $(LIB)libnetio.so $(BIN)netread $(BIN)netwrite
examples: $(BIN)netread $(BIN)netwrite $(BIN)netprint

.PHONY: check
check: $(BIN)netread $(BIN)netprint
	./$(BIN)netread | ./$(BIN)netprint


$(OBJ) $(LIB) $(BIN):
	$(call cmd-print,  MKDIR   $@)
	$(Q)mkdir $@


$(BIN)netread: $(OBJ)netread.o $(OBJ)packet.o | $(BIN)
	$(call cmd-print,  LD      $@)
	$(Q)$(CC) $^ -o $@ $(LDFLAGS)
	$(call cmd-print,  SETCAP  $@)
	$(Q)sudo setcap cap_net_raw+ep $@

$(BIN)netwrite: $(OBJ)netwrite.o $(OBJ)packet.o | $(BIN)
	$(call cmd-print,  LD      $@)
	$(Q)$(CC) $^ -o $@ $(LDFLAGS)
	$(call cmd-print,  SETCAP  $@)
	$(Q)sudo setcap cap_net_raw+ep $@

$(BIN)netprint: $(OBJ)netprint.o $(LIB)libnetio.so | $(BIN)
	$(call cmd-print,  LD      $@)
	$(Q)$(CC) $^ -o $@ $(LDFLAGS) -L$(LIB) -lnetio


$(LIB)libnetio.so: | $(LIB)libnetio.so.$(VERSION) $(LIB)
	$(call cmd-print,  LN      $@)
	$(Q)ln -s libnetio.so.$(VERSION) $@
$(LIB)libnetio.so.$(VERSION): $(patsubst %,$(OBJ)%.so,$(NETIO_OBJECTS)) |$(LIB)
	$(call cmd-print,  LD      $@)
	$(Q)$(CC) $(LSFLAGS) $^ -o $@ $(LDFLAGS)


$(OBJ)%.o:
	$(call cmd-print,  CC      $@)
	$(Q)$(CC) $(CCFLAGS) -c $< -o $@ -I$(INC)

$(OBJ)%.so:
	$(call cmd-print,  CC      $@)
	$(Q)$(CC) $(CCFLAGS) $(CSFLAGS) -c $< -o $@ -I$(INC)


.PHONY: clean
clean:
	$(call cmd-print,  CLEAN)
	-$(Q)rm -rf $(OBJ) $(BIN) $(LIB) *~ $(SRC)*~ $(INC)*~ $(INC)netio/*~
	-$(Q)rm -rf $(MAN)*~
	-$(Q)rm -rf .depends


.depends: $(wildcard $(SRC)*.c)
	$(call cmd-print,  MKDEP   $@)
	$(Q)$(CC) -MM -I$(INC) $^ | sed -r \
          -e 's/^([[:alnum:]_.]+)\.o/$$(OBJ)\1.o $$(OBJ)\1.so/' \
          -e 's/\.h[[:space:]]*$$/.h | $$(OBJ)/' \
        > $@

endif


ifneq ($(V),2)
  Q := @
endif

ifeq ($(V),1)
  define cmd-print
    @echo '$1'
  endef
endif
