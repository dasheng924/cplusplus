.PHONLY :all cl cla
src = $(wildcard ./*.c)
targetc = $(patsubst %.c, % ,$(src))
objc = $(patsubst %.c, %.o, $(src))

#srcpp = $(wildcard ./*.cpp)
#targetcpp = $(patsubst %.cpp, %, $(srcpp))
#objcpp = $(patsubst %.o, %.cpp, $(srcpp))

CC = gcc
#PP = g++

CFLAGS = -g -Wall 
CPPFLAGS = -I ./

ifeq ($(findstring .c, $(src)), .c)
all:$(targetc)
$(targetc):%:%.o
	$(CC) $< -o $@
$(objc):%.o:%.c
	$(CC) -c $< 
endif

cl:
	rm -rf $(objc)
cla:
	rm -rf $(objc)
	rm -rf $(targetc)
	rm -rf a.out
