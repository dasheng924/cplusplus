.PHONLY:all cla cl
src = $(wildcard ./*.c)
target = $(patsubst %.c, %, $(src))
object = $(patsubst %.c, %.o, $(src))

CC = gcc
CFALGS = -g -Wall -lpthread


all:$(target)
$(target):%:%.o
	$(CC) $(CFLAGS) $< -o $@
$(object):%.o:%.c
	$(CC) -c $< 


cl:
	rm -rf $(object)
cla:
	rm -rf $(object)
	rm -rf $(target)
	rm -rf a.out