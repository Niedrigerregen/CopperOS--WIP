#i don't really know what to say here. I HATE Makefile. It's so complicated and can't do anything at all
#Also for compiling make sure that you take this file out of the Makefile folder as it will only search in the Folder it's in.
#Okay well that's half true you can also change the code so it looks into other folders but i won't
 
CC = musl-gcc
CFLAGS_STATIC = -static -O2 -s -I$(CURDIR)/include
CFLAGS_NORMAL = -O2 -s -I$(CURDIR)/include

SRC_DIR = $(CURDIR)/src
ROOTFS = $(CURDIR)/rootfs
BIN_DIR = $(ROOTFS)/bin
INIT = $(ROOTFS)/init

INIT_SRC = $(SRC_DIR)/init.c $(SRC_DIR)/cd.c
COMMAND_SRC := $(filter-out $(INIT_SRC) $(SRC_DIR)/shell.c, $(wildcard $(SRC_DIR)/*.c))
COMMANDS := $(notdir $(COMMAND_SRC:.c=))

all: dirs init commands python googler cpio

cpio:
	cd $(ROOTFS) && find . | cpio -o -H newc > $(CURDIR)/iso/boot/rootfs.cpio
	@echo "built rootfs.cpio → $(CURDIR)/iso/boot/rootfs.cpio"
	rm -rf $(ROOTFS)
	@echo "cleaned up rootfs"

# Copy Python binary & libraries
python:
	mkdir -p $(BIN_DIR)
	cp /usr/bin/python3 $(BIN_DIR)/python3
	chmod +x $(BIN_DIR)/python3
	mkdir -p $(ROOTFS)/usr/lib
	cp -r /usr/lib/python3.* $(ROOTFS)/usr/lib/
	mkdir -p $(ROOTFS)/etc/ssl
	cp -r /etc/ssl/certs $(ROOTFS)/etc/ssl/
	@echo "python3 installed → $(BIN_DIR)/python3 + libraries + certs"

# Copy Googler script
googler:
	cp $(CURDIR)/external/googler/googler $(BIN_DIR)/googler
	chmod +x $(BIN_DIR)/googler
	@echo "googler installed → $(BIN_DIR)/googler"

dirs:
	mkdir -p $(BIN_DIR)
	mkdir -p $(ROOTFS)/data
	mkdir -p $(CURDIR)/iso/boot
	cp $(CURDIR)/data/quotes.txt $(ROOTFS)/data/

init:
	$(CC) $(CFLAGS_STATIC) $(INIT_SRC) -o $(INIT)
	@echo "init compiled → $(INIT)"

commands:
	@for srcfile in $(COMMAND_SRC); \
	do \
		prog=$$(basename $$srcfile .c); \
		$(CC) $(CFLAGS_STATIC) $$srcfile -o $(BIN_DIR)/$$prog; \
		if [ $$? -ne 0 ]; then echo "Error compiling $$prog"; exit 1; fi; \
		echo "$$prog compiled → $(BIN_DIR)/$$prog"; \
	done
	$(CC) $(CFLAGS_STATIC) $(SRC_DIR)/shell.c $(SRC_DIR)/cd.c -o $(BIN_DIR)/shell
	@echo "shell compiled → $(BIN_DIR)/shell"

clean:
	rm -rf $(ROOTFS) $(CURDIR)/iso/boot/rootfs.cpio