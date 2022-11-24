CXX=g++
CXFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic -g -fsanitize=address

TARGET=main
OBJS= main.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXFLAGS) -o $@ $^


