SRC := src/
INC := include/
OBJ := obj/
BIN := bin/
LIB := lib/
MAN := man/
EXP := examples/

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


.PHONY: installdirs
installdirs:
	$(call cmd-print,  INSTALL directories)
	$(Q)mkdir -p $(prefix)/usr/lib
	$(Q)mkdir -p $(prefix)/usr/bin
	$(Q)-mkdir -p $(prefix)/usr/share/man/man1
	$(Q)-mkdir -p $(prefix)/usr/share/man/man3
	$(Q)-mkdir -p $(prefix)/usr/share/man/man7
	$(Q)-mkdir -p $(prefix)/usr/share/netio/bin
	$(Q)-mkdir -p $(prefix)/usr/share/netio/examples

.PHONY: install
install: all installdirs
	$(call cmd-print,  INSTALL binaries)
	$(Q)cp $(BIN)netread $(prefix)/usr/bin/netread
	$(Q)-setcap cap_net_raw+ep $(prefix)/usr/bin/netread \
          || echo "warning: netread will need to be run as root"
	$(Q)cp $(BIN)netwrite $(prefix)/usr/bin/netwrite
	$(Q)-setcap cap_net_raw+ep $(prefix)/usr/bin/netwrite \
          || echo "warning: netwrite will need to be run as root"
	$(call cmd-print,  INSTALL libraries)
	$(Q)cp $(LIB)libnetio.so.$(VERSION) $(prefix)/usr/lib
	$(Q)-rm $(prefix)/usr/lib/libnetio.so.$(MAJOR-VERSION) \
          2>/dev/null || true
	$(Q)ln -s libnetio.so.$(VERSION) \
              $(prefix)/usr/lib/libnetio.so.$(MAJOR-VERSION)
	$(call cmd-print,  INSTALL manpages)
	$(Q)-for f in $(notdir $(wildcard $(MAN)*.1)) ; do \
            gzip -c $(MAN)$$f > $(prefix)/usr/share/man/man1/$$f.gz ; \
        done
	$(Q)-for f in $(notdir $(wildcard $(MAN)*.3)) ; do \
            gzip -c $(MAN)$$f > $(prefix)/usr/share/man/man3/$$f.gz ; \
        done
	$(Q)-for f in $(notdir $(wildcard $(MAN)*.7)) ; do \
            gzip -c $(MAN)$$f > $(prefix)/usr/share/man/man7/$$f.gz ; \
        done
	$(call cmd-print,  INSTALL examples)
	$(Q)-for f in $(filter-out $(BIN)netread $(BIN)netwrite, \
          $(wildcard $(BIN)*)) ; do \
            cp $$f $(prefix)/usr/share/netio/bin ; \
        done
	$(Q)-for f in $(wildcard $(EXP)*) ; do \
            cp $$f $(prefix)/usr/share/netio/examples ; \
        done


$(OBJ) $(LIB) $(BIN):
	$(call cmd-print,  MKDIR   $@)
	$(Q)mkdir $@


$(BIN)netread: $(OBJ)netread.o $(OBJ)packet.o | $(BIN)
	$(call cmd-print,  LD      $@)
	$(Q)$(CC) $^ -o $@ $(LDFLAGS)

$(BIN)netwrite: $(OBJ)netwrite.o $(OBJ)packet.o | $(BIN)
	$(call cmd-print,  LD      $@)
	$(Q)$(CC) $^ -o $@ $(LDFLAGS)

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
	-$(Q)rm -rf $(EXP)*~ $(MAN)*~
	-$(Q)rm -rf .depends


.depends: $(wildcard $(SRC)*.c $(EXP)*.c)
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
