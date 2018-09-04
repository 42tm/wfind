# GNU C++ Compiler
CC = g++
ARG = -std=c++17 -lstdc++fs -O3
ARG_STATIC = -static

# MS Visual C++ Compiler
VCC = cl
V_ARG = /EHsc /std:c++latest /O2
V_ARG_STATIC = /MT

# Install on GNU/Linux
INS_UTIL = cp
INS_TARGET = /usr/bin/
ERR_PRINT = echo

# Naming
MAIN = main.cpp
ifeq ($(OS),Windows_NT)
	NAME = wfind.exe
else
	NAME = wfind
endif
OBJECT = lib/wfind.cpp

# Versioning
VER := $(shell git describe --tags)
# VER := $(shell git rev-parse --short HEAD)
BUILD_VER =_WFIND_VERSION=\"$(VER)\"

# By default, GCC C++ Compiler would be selected
all: gcc

gcc:
	$(CC) $(MAIN) $(OBJECT) -o $(NAME) $(ARG) -D$(BUILD_VER)

gcc-static:
	$(CC) $(MAIN) $(OBJECT) -o $(NAME) $(ARG) $(ARG_STATIC) -D$(BUILD_VER)

vc:
	$(VCC) $(V_ARG) /Fe"$(NAME)" $(MAIN) $(OBJECT) /D$(BUILD_VER)

vc-static:
	$(VCC) $(V_ARG) /Fe"$(NAME)" $(MAIN) $(OBJECT) $(V_ARG_STATIC) /D$(BUILD_VER)

release:


clean:
	$(RM) $(NAME)
	$(RM) *.obj

install:
ifeq ($(OS),Windows_NT)
	$(ERR_PRINT) "\"make install\" is not available on Windows NT!
else
	$(INS_UTIL) $(NAME) $(INS_TARGET)	
endif
