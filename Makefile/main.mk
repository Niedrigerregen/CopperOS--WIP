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
COMMAND_SRC := $(filter-out $(INIT_SRC), $(wildcard $(SRC_DIR)/*.c))
COMMANDS := $(notdir $(COMMAND_SRC:.c=))

all: dirs init commands

dirs:
	mkdir -p $(BIN_DIR)


init:
	$(CC) $(CFLAGS_STATIC) $(INIT_SRC) -o $(INIT)
	@echo "init compiled → $(INIT)"


commands:
	@for srcfile in $(COMMAND_SRC); do \
		prog=$$(basename $$srcfile .c); \
		$(CC) $(CFLAGS_NORMAL) $$srcfile -o $(BIN_DIR)/$$prog; \
		if [ $$? -ne 0 ]; then echo "Error compiling $$prog"; exit 1; fi; \
		echo "$$prog compiled → $(BIN_DIR)/$$prog"; \
	done

clean:
	rm -rf $(BIN_DIR) $(INIT)