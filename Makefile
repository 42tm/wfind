CC = g++
ARG = -std=c++17 -lstdc++fs
MAIN = main.cpp
ifeq ($(OS),Windows_NT)
	NAME = wfind.exe
else
	NAME = wfind
endif
OBJECT = lib/wfind.cpp

all:
	$(CC) $(MAIN) $(OBJECT) -o $(NAME) $(ARG)
