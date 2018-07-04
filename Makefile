# GNU C++ Compiler
CC = g++
ARG = -std=c++17 -lstdc++fs

# MS Visual C++ Compiler
VCC = cl
V_ARG = /clr /std:c++latest

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