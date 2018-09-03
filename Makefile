# GNU C++ Compiler
CC = g++
ARG = -std=c++17 -lstdc++fs

# MS Visual C++ Compiler
VCC = cl
V_ARG = /clr /std:c++latest

# Install on Linux
INS_UTIL = cp
INS_TARGET = /usr/bin/
ERR_PRINT = echo

MAIN = main.cpp
ifeq ($(OS),Windows_NT)
	NAME = wfind.exe
else
	NAME = wfind
endif
OBJECT = lib/wfind.cpp

all: gcc

gcc:
	$(CC) $(MAIN) $(OBJECT) -o $(NAME) $(ARG)

vc:
	$(VCC) $(V_ARG) /Fe"$(NAME)" $(MAIN) $(OBJECT)

clean:
	$(RM) $(NAME)
	$(RM) *.obj

install:
ifeq ($(shell uname -s),Linux)
	$(INS_UTIL) $(NAME) $(INS_TARGET)
else
		$(ERR_PRINT) "\"make install\" is only available for Linux!
endif
