CC := g++
CFLAGS := -Wall -g
TARGET := array

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp) $(wildcard *.cc) $(wildcard *.c)

# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
#OBJS := $(patsubst %.cpp,%.o,$(SRCS))
OBJS += $(patsubst %.c,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $<
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
%.o: %.cc
	$(CC) $(CFLAGS) -c $<
	
clean:
	rm -rf $(TARGET) *.o
	
.PHONY: all clean
