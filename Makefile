CXX=g++
CXFLAGS= -std=c99 -Wall -Wextra -Werror -pedantic -g -fsanitize=address -lgtest

TARGET=test
OBJS= test.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(TARGET)

.PHONY:
	clean
