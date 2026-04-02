# CopperOS Makefile
# Most stuff is statically linked, but search needs dynamic linking because libcurl is a pain

CC = musl-gcc
CFLAGS_STATIC = -static -O2 -s -I$(CURDIR)/include

SRC_DIR = $(CURDIR)/src
ROOTFS  = $(CURDIR)/rootfs
BIN_DIR = $(ROOTFS)/bin
INIT = $(ROOTFS)/init

INIT_SRC = $(SRC_DIR)/init.c $(SRC_DIR)/cd.c
SPECIAL_SRC = $(SRC_DIR)/search.c

COMMAND_SRC := $(filter-out \
	$(INIT_SRC) \
	$(SRC_DIR)/shell.c \
	$(SPECIAL_SRC), \
	$(wildcard $(SRC_DIR)/*.c))

.PHONY: all dirs init commands search busybox copy-libs cpio clean

all: dirs init commands search busybox copy-libs cpio

cpio:
	cd $(ROOTFS) && find . | cpio -o -H newc > $(CURDIR)/iso/boot/rootfs.cpio
	#rm -rf $(ROOTFS)

dirs:
	mkdir -p $(BIN_DIR)
	mkdir -p $(ROOTFS)/data
	mkdir -p $(ROOTFS)/lib
	mkdir -p $(ROOTFS)/lib64
	mkdir -p $(ROOTFS)/dev
	mkdir -p $(ROOTFS)/proc
	mkdir -p $(ROOTFS)/sys
	mkdir -p $(ROOTFS)/tmp
	mkdir -p $(ROOTFS)/etc
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

# BusyBox provides ip, udhcpc, and other networking tools that i am too dumb to implement myself
busybox:
	@echo "Adding BusyBox..."
	@BUSYBOX_PATH=$$(command -v busybox 2>/dev/null || echo ""); \
	if [ -z "$$BUSYBOX_PATH" ]; then \
		echo "Error: busybox not found in PATH. Please install busybox-static."; \
		exit 1; \
	fi; \
	echo "Found busybox at $$BUSYBOX_PATH"; \
	cp "$$BUSYBOX_PATH" $(BIN_DIR)/busybox
	@# Create symlinks for the commands needed
	@ln -sf busybox $(BIN_DIR)/ip
	@ln -sf busybox $(BIN_DIR)/udhcpc
	@ln -sf busybox $(BIN_DIR)/ifconfig
	@ln -sf busybox $(BIN_DIR)/route
	@echo "BusyBox added."

# first time linking dynamically in an Operating System - kinda nervous https://tropedia.fandom.com/wiki/Shy_Finger-Twiddling
search:
	gcc -O2 -s -I$(CURDIR)/include $(SRC_DIR)/search.c -o $(BIN_DIR)/search -lcurl

# Grab all the .so files search needs and dump them into rootfs/lib
# Also copy the dynamic linker to the location the binary expects (lib64)
copy-libs:
	@echo "Copying dynamic libraries for search..."
	@mkdir -p $(ROOTFS)/lib
	@mkdir -p $(ROOTFS)/lib64
	@ldd $(BIN_DIR)/search 2>/dev/null | grep "=> /" | awk '{print $$3}' | while read lib; do \
		if [ -n "$$lib" ] && [ -f "$$lib" ]; then \
			echo "  Copying $$lib"; \
			cp "$$lib" $(ROOTFS)/lib/; \
		fi \
	done
	@# Copy dynamic linker to the location the binary expects (lib64)
	@if [ -f /lib64/ld-linux-x86-64.so.2 ]; then \
		echo "  Copying /lib64/ld-linux-x86-64.so.2 to lib64/"; \
		cp /lib64/ld-linux-x86-64.so.2 $(ROOTFS)/lib64/; \
	elif [ -f /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 ]; then \
		echo "  Copying /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 to lib64/"; \
		cp /lib/x86_64-linux-gnu/ld-linux-x86-64.so.2 $(ROOTFS)/lib64/; \
	else \
		echo "  WARNING: Could not find dynamic linker"; \
	fi
	@echo "Library copy complete."

clean:
	#rm -rf $(ROOTFS) $(CURDIR)/iso/boot/rootfs.cpio