CFLAGC= -c -g -Wall -w
LDFLAGC=
CPPFLAGS= -I./
CC = gcc 

src = $(wildcard *c)
obj = $(patsubst %.c,%.o, $(src))

target = main 

$(target):$(obj)
		$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGC) $(CPPFLAGS) $< -o $@

.PHONY:clean
clean:
	-rm -f $(obj)    
	-rm -f $(target)
