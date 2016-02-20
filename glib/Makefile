


CC		= gcc
CFLAGS		= -std=gnu11 -Wall -Wextra -O0 -g -fdiagnostics-color=auto $(shell pkg-config --cflags glib-2.0)
LDLIBS		= $(shell pkg-config --libs glib-2.0)

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
BINS		= $(SRCS:.c=)

all: $(BINS)

# generate targets
define generateRules = 
$(1): $(1).o
$(1).o: $(1).c Makefile
endef
$(foreach i,$(BINS),$(eval $(call generateRules, $(i))))

# cleanup 
clean:
	rm -f $(OBJS)
distclean: clean
	rm -f $(BINS)

.PHONY: all clean distclean
