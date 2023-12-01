
CC = gcc
CFLAGS = -Wall -Werror
BIN = dirsumm
OBJS = dirsumm.o dirinfo.o filtype.o
LDFLAGS = -lncurses
ECHO = echo

-include $(OBJS:.o=.d)


all: $(BIN) etags

$(BIN): $(OBJS)
	@$(ECHO) Linking $@
	@$(CC) $^ -o $@ $(LDFLAGS)

-include $(OBJS:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MF $*.d -c $<




main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	rm -f main
