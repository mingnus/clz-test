PROGRAMS=clz

SOURCE=main.c \
	clz.c \
	clz-bsrch.c \
	clz-bshift.c \
	clz-harley.c \
	clz-iter.c \
	clz-rcs.c

CC:=gcc
CFLAGS+=-O0
OBJECTS:=$(subst .c,.o,$(SOURCE))

%.o: %.c
	$(V) $(CC) -c $(CPPFLAGS) $(CFLAGS) -o $@ $<

all: $(PROGRAMS)

clz: $(OBJECTS)
	$(V) $(CC) $(CFLAGS) $(LDFLAGS) -o $@ $+

.PHONY: clean
clean:
	$(RM) *.o
	$(RM) clz
