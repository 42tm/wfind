CC = g++
ARG = -std=c++17 -lstdc++fs
NAME = main
OBJECT = src/wfind.cpp

all:
	$(CC) $(NAME).cpp $(OBJECT) -o $(NAME) $(ARG)