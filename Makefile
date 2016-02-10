


CC		= gcc
CFLAGS		= $(shell pkg-config --cflags gtk+-3.0)
LDLIBS		= $(shell pkg-config --libs gtk+-3.0)

EXAMPLE_SRCS	= $(wildcard example*.c)
EXAMPLE_OBJS	= $(EXAMPLE_SRCS:.c=.o)
EXAMPLE_BINS	= $(EXAMPLE_SRCS:.c=)

all: $(EXAMPLE_BINS)

# generate targets
define generateRules = 
$(1): $(1).o
$(1).o: $(1).c
endef
$(foreach i,$(EXAMPLE_BINS),$(eval $(call generateRules, $(i))))

# cleanup 
clean:
	rm -f $(EXAMPLE_OBJS)
distclean: clean
	rm -f $(EXAMPLE_BINS)

.PHONY: all clean distclean
