#i don't really know what to say here. I HATE Makefile. It's so complicated and can't do anything at all
#Also for compiling make sure that you take this file out of the Makefile folder as it will only search in the Folder it's in.
#Okay well that's half true you can also change the code so it looks into other folders but i won't

CC = musl-gcc
CFLAGS_STATIC = -static -O2 -s -I$(CURDIR)/include

SRC_DIR = $(CURDIR)/src
ROOTFS  = $(CURDIR)/rootfs
BIN_DIR = $(ROOTFS)/bin
INIT = $(ROOTFS)/init

CURL_LIBS = -lcurl -lssl -lcrypto -lz -lpthread

INIT_SRC = $(SRC_DIR)/init.c $(SRC_DIR)/cd.c
SPECIAL_SRC = $(SRC_DIR)/search.c

COMMAND_SRC := $(filter-out \
	$(INIT_SRC) \
	$(SRC_DIR)/shell.c \
	$(SPECIAL_SRC), \
	$(wildcard $(SRC_DIR)/*.c))

.PHONY: all dirs init commands search cpio clean

all: dirs init commands search cpio

cpio:
	cd $(ROOTFS) && find . | cpio -o -H newc > $(CURDIR)/iso/boot/rootfs.cpio
	rm -rf $(ROOTFS)

dirs:
	mkdir -p $(BIN_DIR)
	mkdir -p $(ROOTFS)/data
	mkdir -p $(CURDIR)/iso/boot
	cp $(CURDIR)/data/quotes.txt $(ROOTFS)/data/
	cp $(CURDIR)/data/aliases.txt $(ROOTFS)/data/

init:
	$(CC) $(CFLAGS_STATIC) $(INIT_SRC) -o $(INIT)

commands:
	@for srcfile in $(COMMAND_SRC); do \
		prog=$$(basename $$srcfile .c); \
		$(CC) $(CFLAGS_STATIC) $$srcfile -o $(BIN_DIR)/$$prog; \
		if [ $$? -ne 0 ]; then echo "Error compiling $$prog"; exit 1; fi; \
	done
	$(CC) $(CFLAGS_STATIC) $(SRC_DIR)/shell.c $(SRC_DIR)/cd.c -o $(BIN_DIR)/shell

search:
	$(CC) $(CFLAGS_STATIC) -I/path/to/musl/include \
		$(SRC_DIR)/search.c -o $(BIN_DIR)/search \
		-L/path/to/musl/lib -lcurl -lssl -lcrypto -lz -lpthread
		
clean:
	rm -rf $(ROOTFS) $(CURDIR)/iso/boot/rootfs.cpio