SRC := src/
INC := include/
OBJ := obj/
BIN := bin/
LIB := lib/

MAJOR-VERSION:=0
MINOR-VERSION:=0
FIX-VERSION  :=0
VERSION      :=$(MAJOR-VERSION).$(MINOR-VERSION).$(FIX-VERSION)

CC      := gcc
CCFLAGS := -Wall -Wextra -pedantic
CSFLAGS := -fPIC -DNETIO_VERSION=\"$(VERSION)\"
LDFLAGS := 
LSFLAGS := -shared


default: check


all: $(LIB)libnetio.so $(BIN)netread $(BIN)netwrite
examples: $(BIN)netread $(BIN)netwrite $(BIN)netprint

check: $(BIN)netread $(BIN)netprint
	./$(BIN)netread | ./$(BIN)netprint


$(OBJ) $(LIB) $(BIN):
	mkdir $@


$(BIN)netread: $(OBJ)netread.o $(OBJ)packet.o | $(BIN)
	$(CC) $^ -o $@ $(LDFLAGS)
	sudo setcap cap_net_raw+ep $@

$(BIN)netwrite: $(OBJ)netwrite.o | $(BIN)
	$(CC) $^ -o $@ $(LDFLAGS)
	sudo setcap cap_net_raw+ep $@

$(BIN)netprint: $(OBJ)netprint.o $(LIB)libnetio.so | $(BIN)
	$(CC) $^ -o $@ $(LDFLAGS) -L$(LIB) -lnetio


$(LIB)libnetio.so: $(LIB)libnetio.so.$(VERSION) | $(LIB)
	ln -s $(notdir $<) $@
$(LIB)libnetio.so.$(VERSION): $(OBJ)context.so $(OBJ)header.so $(OBJ)netio.so \
                              $(OBJ)packet.so $(OBJ)raw.so | $(LIB)
	$(CC) $(LSFLAGS) $^ -o $@ $(LDFLAGS)


$(OBJ)%.o: $(SRC)%.c $(wildcard $(INC)*.h) | $(OBJ)
	$(CC) $(CCFLAGS) -c $< -o $@ -I$(INC)

$(OBJ)%.so: $(SRC)%.c $(wildcard $(INC)*.h) | $(OBJ)
	$(CC) $(CCFLAGS) $(CSFLAGS) -c $< -o $@ -I$(INC)


clean:
	-rm -rf $(OBJ) $(BIN) $(LIB) *~ $(SRC)*~ $(INC)*~
