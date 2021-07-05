CC := g++
CFLAGS := -Wall -g -std=c++11 -std=gnu++11 
TARGET := exe

# $(wildcard *.cpp /xxx/xxx/*.cpp): get all .cpp files from the current directory and dir "/xxx/xxx/"
SRCS := $(wildcard *.cpp) $(wildcard *.cc)

# $(patsubst %.cpp,%.o,$(SRCS)): substitute all ".cpp" file name strings to ".o" file name strings
#OBJS := $(patsubst %.cpp,%.o,$(SRCS))
OBJS += $(patsubst %.cc,%.o,$(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<
%.o: %.cc
	$(CC) $(CFLAGS) -c $<
clean:
	rm -rf $(TARGET) *.o

check:
	@./$(TARGET)
	
.PHONY: all clean check
