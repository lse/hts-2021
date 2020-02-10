CFLAGS = -Wall -Wextra \
	 -fno-stack-protector \
	 -fno-builtin \


DISABLE_EH_FRAME = \
	 -fno-unwind-tables \
	 -fomit-frame-pointer \
	 -fno-exceptions \
	 -fno-asynchronous-unwind-tables \
	 -fno-unwind-tables

MY_LD ?= gcc -static -nostdlib

BINS = \
	simple \
	hello \
	vars \
	simple-debug \
	hello-debug \
	vars-debug \

all: $(BINS)

simple.o: CFLAGS += $(DISABLE_EH_FRAME)
simple: simple.o

hello.o: CFLAGS += $(DISABLE_EH_FRAME)
hello: hello.o

vars.o: CFLAGS += $(DISABLE_EH_FRAME)
vars: vars.o

simple-debug.o: CFLAGS += -g
simple-debug: simple-debug.o

hello-debug.o: CFLAGS += -g
hello-debug: hello-debug.o

vars-debug.o: CFLAGS += -g
vars-debug: vars-debug.o

%: %.o
	$(MY_LD) -o $@ $^

clean:
	$(RM) *.o $(BINS)
