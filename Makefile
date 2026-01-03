# Program name
NAME := term-holdem

# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -std=c11 -Iinclude

# Directories
SRC_DIR := src
BUILD_DIR := build

# Source files (ANSI-based + game logic)
SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/game.c \
	$(SRC_DIR)/term.c \
	$(SRC_DIR)/input.c \
	$(SRC_DIR)/render.c 

# Object files
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Install locations
PREFIX ?= /usr/local
BINDIR := $(PREFIX)/bin

# Default target
all: $(NAME)

# Link binary
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(BUILD_DIR) $(NAME)

# Install binary
install: $(NAME)
	mkdir -p $(BINDIR)
	cp $(NAME) $(BINDIR)/$(NAME)

# Uninstall binary
uninstall:
	rm -f $(BINDIR)/$(NAME)

.PHONY: all clean install uninstall
