
CC = gcc
CFLAGS = -ggdb -Wall -Werror
BIN = dirsumm
OBJS = dirsumm.o dirinfo.o filetype.o
LDFLAGS = -lncurses
ECHO = echo
RM = rm -f

-include $(OBJS:.o=.d)


all: $(BIN) 

$(BIN): $(OBJS)
	@$(ECHO) Linking $@
	@$(CC) $^ -o $@ $(LDFLAGS)

-include $(OBJS:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MF $*.d -c $<




main: main.c
	$(CC) $(CFLAGS) -o main main.c

clean:
	@$(RM) *.o a.out $(BIN) *.d TAGS core vgcore.* gmon.out
