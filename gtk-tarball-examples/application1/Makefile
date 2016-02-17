

APPNAME		= app

CC		= gcc
CFLAGS		= -std=gnu11 -Wall -Wextra -O0 -g -Wno-unused-parameter $(shell pkg-config --cflags gtk+-3.0)
LDLIBS		= $(shell pkg-config --libs gtk+-3.0)

HDRS		= $(wildcard *.h)
SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

all: $(APPNAME)

# Dumb dependency management
$(APPNAME): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LDLIBS) -o $@
$(OBJS): $(SRCS)
$(SRCS): $(HDRS)

clean:
	rm -f *.o
distclean: clean
	rm -f $(APPNAME)

.PHONY: all clean distclean
